/* swap 2 different numbers, the same type */
#include<stdio.h>
#include"../header/switch.h"

void inplace_swap(int *x,int *y){
	//Decimal_to_Binary(*x);
	//Decimal_to_Binary(*y);
	*y = *x ^ *y;
	//printf("exclusive-or = %d\n",*y);
	//Decimal_to_Binary(*x);
	//Decimal_to_Binary(*y);
	*x = *y ^ *x;
	//printf("exclusive-or = %d\n",*x);
	//Decimal_to_Binary(*x);
	//Decimal_to_Binary(*y);
	*y = *x ^ *y;
	//printf("exclusive-or = %d\n",*y);
}

void swap(){
	int i;
	int par[2];
	char p;
start:
	printf("switch integer or character to be done,integer input 1 and character input 2,exit input 3\n");
	scanf("%d",&i);
	switch(i){
	case 1:
		goto integer;
		break;
	case 2:
		goto character;
		break;
	case 3:
		goto end;
		break;
	default:
		printf("input error");
		goto start;
	}
character:
	printf("input two characters\n");
	i = 0;
	while(i<2){
		p = getchar();
		//printf("%c\n",p);
		if(p != ',' && p != ' ' && p != 10){
			par[i] = p - '\0';//or par[i] = (int)p
			i++;
		}
	}
	//printf("%c %c\n",par[0],par[1]);
	goto do_char;
integer:
	printf("input two integers\n");
	scanf("%d",&par[0]);
	scanf("%d",&par[1]);
	goto do_int;
do_char:
	inplace_swap(&par[0],&par[1]);
	printf("%c %c\n",par[0],par[1]);
	goto start;
do_int:
	inplace_swap(&par[0],&par[1]);
	printf("%d %d\n",par[0],par[1]);
	goto start;
end:
	printf("good bye\n");
}