CFLAGS = -fno-stack-protector -no-pie
CC = gcc

lab1-4: stack-pivoting.c
	$(CC) $(CFLAGS) -o $@ $^
	strip $@