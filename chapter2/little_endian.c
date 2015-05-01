/* check for little endian */
/* 某个类型的指针实际上是一组连续的字节序列（长度待定） */

#include<stdio.h>
#include"little_endian.h"

void self(){
	int i;
	printf("input a hexadecimal\n");
	scanf("%x",&i);
	char *p = NULL;
	p = &i;
	printf("%x ----> %x\n",p,*p);
	printf("%x ----> %x\n",p+1,*(p+1));
	printf("%x ----> %x\n",p+2,*(p+2));
	printf("%x ----> %x\n",p+3,*(p+3));
}

//typedef unsigned char *byte_pointer;//指向一个char的指针等于指向一个byte的指针

void show_bytes(byte_pointer start,int len){
	int i;
	for(i=0;i<len;i++)
		printf("%.2x",start[i]);
	printf("\n");
}

void show_int(int x){
	show_bytes((byte_pointer)&x,sizeof(int));
}

void show_float(float x){
	show_bytes((byte_pointer)&x,sizeof(float));
}

void show_pointer(void *x){
	show_bytes((byte_pointer)&x,sizeof(void *));
}

void display_little_endian(){

	void *p = malloc(sizeof(void *));
	show_int(1);
	show_float(1);
	show_pointer(p);
	printf("%.2x\n",p);

	
	int hexadecimal[2];
	printf("enter two hexadecimals\n");
	scanf("%x",&hexadecimal[0]);
	scanf("%x",&hexadecimal[1]);
	printf("%x,%x\n",hexadecimal[0],hexadecimal[1]);
	printf("%x\n",*((char *)hexadecimal));
	printf("%x\n",*((char *)(hexadecimal+1)));
	printf("%x\n",*(((char *)hexadecimal)+1));
 	show_int(hexadecimal[0]);
	show_int(hexadecimal[1]); 	
} 



