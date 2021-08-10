CFLAGS = -fno-stack-protector -no-pie
CC = gcc

lab1-1: got-hijack.c
	$(CC) $(CFLAGS) -o $@ $^
	strip $@