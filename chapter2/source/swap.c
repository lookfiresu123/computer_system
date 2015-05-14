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

void reverse_array(int a[],int cnt){
	int first,last;
	for(first=0,last=cnt-1;first<=last;first++,last--){
		if(first != last)
			inplace_swap(&a[first],&a[last]);
	}
}

void swap(){
	int i;
	int par[2];
	char p;
start:
	printf("switch integer or character to be done,integer input 1 \
	and character input 2,and array input 3,exit input 4\n");
	scanf("%d",&i);
	switch(i){
	case 1:
		goto integer;
		break;
	case 2:
		goto character;
		break;
	case 3:
		goto array;
		break;
	case 4:
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
		if(p != ',' && p != ' ' && p != 10){
			par[i] = p - '\0';//or par[i] = (int)p
			i++;
		}
	}
	goto do_char;
integer:
	printf("input two integers\n");
	scanf("%d",&par[0]);
	scanf("%d",&par[1]);
	goto do_int;
array:
	printf("input 1 for int and 2 for char array\n");
	int j,length,z;
	int array[100];
	int k;
	scanf("%d",&j);
	switch(j){
	case 1:
		printf("enter the length of array\n");
		scanf("%d",&length);
		printf("input for array\n");
		for(k=0;k<length;k++){
			scanf("%d",&array[k]);
			//printf("%d\n",array[k]);
		}
		goto do_array_int;
		break;
	case 2:
		printf("enter the length of array\n");
		scanf("%d",&length);
		printf("input for array\n");
		char q;
		k=0;
		while(k<length){
			q = getchar();
			if(q != ',' && q != ' ' && q != 10){
				array[k] = q - '\0';//or par[i] = (int)p
				k++;
			}
		}
		goto do_array_char;
		break;
	default:
		printf("input error");
		goto array;
		break;
	}
	goto array;
do_char:
	inplace_swap(&par[0],&par[1]);
	printf("%c %c\n",par[0],par[1]);
	goto start;
do_int:
	inplace_swap(&par[0],&par[1]);
	printf("%d %d\n",par[0],par[1]);
	goto start;
do_array_int:
	reverse_array(array,length);
	for(z=0;z<length;z++)
		printf("%d ",array[z]);
	printf("\n");
	goto start;
do_array_char:
	reverse_array(array,length);
	for(z=0;z<length;z++)
		printf("%c ",array[z]+'\0');
	printf("\n");
	goto start;
end:
	printf("good bye\n");
}