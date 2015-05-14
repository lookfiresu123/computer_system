#include<stdio.h>
#include"../header/switch.h"

int word_size = 32;//the size of integer

void Build(int decimal,int binary[]){
	//int binary[word_size];
    int i = 0;
    int j;
    //initial
    for(i=0;i<word_size;i++)
    	binary[i] = 0;
    i = word_size - 1;
    while((decimal / 2) != 0){
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i--;
    }
    binary[i] = decimal % 2;
    //return binary;
}

int bis(int x,int y){
	int result,i;
	int binary[2][word_size];
	Build(x,binary[0]); 
	Build(y,binary[1]);
	for(i=0;i<word_size;i++){
		if(binary[1][i] == 1)
			binary[0][i] = 1;
	}
	result = Binary_to_Decimal(binary[0],word_size);
	//printf("%d\n",result);
	return result;
}

int bic(int x,int y){
	int result,i;
	int binary[2][word_size];
	Build(x,binary[0]); 
	Build(y,binary[1]);
	for(i=0;i<word_size;i++){
		if(binary[1][i] == 1)
			binary[0][i] = 0;
	}
	result = Binary_to_Decimal(binary[0],word_size);
	//printf("%d\n",result);
	return result;
}

int bool_or(int x,int y){
	int result;
	result = bis(x,y);
	return result;
}

int bool_xor(int x,int y){
	int result;
	result = bis(bic(x,y),bic(y,x));
	return result;
}

void or_xor_bis_bic(){
start:
	printf("switch bis to 1,bic to 2,or to 3,xor to 4,exit to 5\n");
	int i,result,x,y;
	char *str[4] = {"bis","bic","or","xor"};
	scanf("%d",&i);
	//printf("%d %d\n",x,y);
	switch(i){
	case 1:
		printf("input x and y\n");
		scanf("%d",&x);
		scanf("%d",&y);
		result = bis(x,y);
		break;
	case 2:
		printf("input x and y\n");
		scanf("%d",&x);
		scanf("%d",&y);
		result = bic(x,y);
		break;
	case 3:
		printf("input x and y\n");
		scanf("%d",&x);
		scanf("%d",&y);
		result = bool_or(x,y);
		break;
	case 4:
		printf("input x and y\n");
		scanf("%d",&x);
		scanf("%d",&y);
		result = bool_xor(x,y);
		break;
	case 5:
		goto end;
		break;
	default:
		printf("input error\n");
		break;
	}
	printf("%d %s %d = %d\n",x,str[i-1],y,result);
	goto start;
end:
	printf("good bye\n");
}