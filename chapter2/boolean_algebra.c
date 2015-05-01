#include<stdio.h>

void main(){
	int hexadecimal1,hexadecimal2;
	printf("input two hexadecimals\n");
	scanf("%x",&hexadecimal1);
	scanf("%x",&hexadecimal2);
	printf("~ = %x\n",~ hexadecimal1);
	printf("& = %x\n",hexadecimal1 & hexadecimal2);
	printf("| = %x\n",~hexadecimal1 | hexadecimal2);
	printf("^ = %x\n",~hexadecimal1 ^ hexadecimal2);
}