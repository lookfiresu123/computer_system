/* 
 * printf different types of data size 
 * word size is 64 bits
*/

#include<stdio.h>

int data_size(){
	printf("char_size = %d bytes\n",sizeof(char));
	printf("short int_size = %d bytes\n",sizeof(short int));
	printf("int_size = %d bytes\n",sizeof(int));
	printf("long int_size = %d bytes\n",sizeof(long int));// a word size
	printf("long long int_size = %d bytes\n",sizeof(long long int));
	printf("char *_size = %d bytes\n",sizeof(char *));// a word size
	printf("float_size = %d bytes\n",sizeof(float));
	printf("double_size = %d bytes\n",sizeof(double));
	return 0;
}

void main(){
	data_size();
}