#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int getLens()
{
    char buf[8];
    int len;
    do {
        printf("length:");
        read(0, buf, 0x10);
        len = atoi(buf);
        if (len <= 0x20) break;
        else puts("the length must <= 0x20.");
    } while (1);
    printf("Need to modify?(y/n)");
    read(0, buf, 0x10);
    if(buf[0] == 'y' || buf[0] == 'Y')
    {
        do {
            printf("length:");
            read(0, buf, 0x10);
            len = atoi(buf);
            if (len <= 0x20) break;
            else puts("the length must <= 0x20.");
        } while (1);
    }
    return len;
}

void reader()
{
    int len;
    char buf[0x20];
    puts("> Here is a character reader. <");
    puts("Tell me your text length.");
    len = getLens();
    puts("Type your text now.");
    printf("# ");
    read(0, buf, len);
    return;
}

int main(int argc, char const *argv[])
{
    setvbuf(stdout, 0, _IONBF, 0);
    setvbuf(stderr, 0, _IONBF, 0);
    setvbuf(stdin,  0, _IONBF, 0);

    reader();
    return 0;
}

