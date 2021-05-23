#include <stdio.h>
#include <stdlib.h>
int main(){
	char *p;	
	p = malloc(0x40);
	free(p);
	printf("Has been freed\n");
	read(0,p,100);
	printf("%s",p);
}
