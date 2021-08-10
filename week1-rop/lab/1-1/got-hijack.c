#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

unsigned long long array[3];

void func(){
    system("echo 'need 3 nums'");
    int i;
    int idx;
    unsigned long long d;
    for (i = 0; i < 3; i++)
    {
        puts("index:");
        scanf("%d", &idx);
        puts("value:");
        scanf("%llu", &d);
        if(idx < 3){
            array[idx] = d;
        }
    }
    puts("Give you a useful string:");
    printf("/bin/sh");
}

int main(int argc, char const *argv[])
{
    func();
    return 0;
}

