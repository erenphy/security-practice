#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int *a[7];
	int index = 2;
	char *payload = malloc(0x100);
	memcpy(payload,"\x60\x62\x75\x55\x55\x55\x00\x00",0x8);
	//need to close ALSR,using echo 0 > /proc/sys/kernel/randomize_va_space
	for(int i=0;i<7;i++){
		a[i] = malloc(0x80);	
	}
	for(int i=0;i<7;i++){
		free(a[i]);
		//a[i] = NULL;	
	}
	memcpy(a[6],payload,0x8);
	a[0] = malloc(0x80);
	a[1] = malloc(0x80);
	printf("a[1]'s addr is %p\n",a[1]);
	return 0;
}
