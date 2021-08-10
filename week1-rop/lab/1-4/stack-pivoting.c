#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void init(){
    setvbuf(stdout, 0, _IONBF, 0);
    setvbuf(stderr, 0, _IONBF, 0);
    setvbuf(stdin,  0, _IONBF, 0);
}

void func(){
    char buf[0x18];
    printf("your input:\n");
    read(0, buf, 0x30);
    printf("You say %s\n", buf);
}

int main(int argc, char const *argv[])
{
    init();
    func();
    return 0;
}
