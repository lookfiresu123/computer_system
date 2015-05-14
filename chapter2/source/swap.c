/* swap 2 numbers */
#include<stdio.h>
#include"../header/switch.h"

void inplace_swap(int *x,int *y){
	Decimal_to_Binary(*x);
	Decimal_to_Binary(*y);
	*y = *x ^ *y;
	printf("exclusive-or = %d\n",*y);
	Decimal_to_Binary(*x);
	Decimal_to_Binary(*y);
	*x = *y ^ *x;
	printf("exclusive-or = %d\n",*x);
	Decimal_to_Binary(*x);
	Decimal_to_Binary(*y);
	*y = *x ^ *y;
	printf("exclusive-or = %d\n",*y);
}

void swap(){
	int x,y;
	printf("input two integers\n");
	scanf("%d",&x);
	scanf("%d",&y);
	inplace_swap(&x,&y);
}