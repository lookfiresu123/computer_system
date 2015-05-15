#include<stdio.h>
#include"../header/switch.h"

//a mathod of building equivalence( == )
void build_equivalence(){
	int par[2];
	char str;
	int i = 0;
	while(i<2){
		str = getchar();
		if(str != '\n' && str != ' ' && str != ','){
			par[i] = (int)str;
			i++;
		}
	}
	if(par[0] == par[1])
		printf("success\n");
	else
		printf("failed\n");
	if(!~(par[0] ^ (~par[1])))
		printf("success\n");
	else
		printf("failed\n");
}

/*  the data type of shift must be unsigned, otherwise it will be error
 *  when i >= sizeof(int), it will be restart to shift
 *  c language: unsigned types --> logical >> ; signed types --> arithmetic >>
 *  java language: >> --> arithmetic >> ; >>> --> logical >>
 */

//shift operation to left
void shift_left(unsigned int a){
	unsigned int i;
	unsigned int x = a;
	printf("origin data is : ");
	Decimal_to_Binary(x);
	for(i=0;i<64;i++){
		x = a << i;
		printf("shift left %d : ",i);
		Decimal_to_Binary(x);
	}
}


//shift operation to right
void shift_right(unsigned int a){
	unsigned int i;
	unsigned int x = a;
	printf("origin data is : ");
	Decimal_to_Binary(x);
	for(i=0;i<64;i++){
		x = a >> i;
		printf("shift right %d : ",i);
		Decimal_to_Binary(x);
	}
}

void test(){
	unsigned int a;
	printf("input a number\n");
	scanf("%x",&a);
	printf("shift_left: \n");
	shift_left(a);
	printf("shift_left: \n");
	shift_right(a);
}