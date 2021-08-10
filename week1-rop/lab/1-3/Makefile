CFLAGS = -fno-stack-protector -no-pie
CC=gcc

lab1-3: text-reader.c
	$(CC) $(CFLAGS) -o $@ $^
	strip $@