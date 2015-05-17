/* switch from decimal to hexadecimal and binary */
#include<stdio.h>
#include<math.h>

int array_size = 32;

int pow_vary(int x,int y){
    int result = 1;
    int i;
    for(i=0;i<y;i++){
        result = result * x;
    }
    return result;
}

void Decimal_to_Binary(unsigned int decimal){
    unsigned int binary[array_size];
    //initial
    int i=0;
    for(i=0;i<array_size;i++)
        binary[i] = 0;
    i=0;
    int j;
    while((decimal / 2) != 0){
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }
    binary[i] = decimal % 2;
    for(j=array_size-1;j>=0;j--){
        printf("%d",binary[j]);
    }
    printf("\n");
}

int Binary_to_Decimal_signed(int binary[],int length){
    int Decimal = 0;
    int i,j;
    int temp = 0 - binary[length-1] * pow_vary(2,length-1);
    for(i=0;i<length-1;i++)
        Decimal = Decimal + binary[i] * pow_vary(2,i);
    Decimal = temp + Decimal;
    printf("%d\n",Decimal);
    return Decimal;
}

unsigned int Binary_to_Decimal(unsigned int binary[],int length){
    unsigned int Decimal = 0;
    int i,j;
    for(i=0;i<length;i++){
        int exp = 1;
        for(j=0;j<length-i-1;j++){
            exp *= 2;
        }
        Decimal = Decimal + (binary[i] * exp);
    }
    //printf("%d\n",Decimal);
    return Decimal;
}

void Decimal_to_Hexadecimal(int decimal){
    int Hexadecimal[array_size];
    char hexadecimal[array_size];
    int i=0;
    int j;
    while((decimal / 16) != 0){
        Hexadecimal[i] = decimal % 16;
        decimal = decimal / 16;
        i++;
    }
    Hexadecimal[i] = decimal % 16;
    for(j=i;j>=0;j--){
        if(Hexadecimal[j] > 9)
            hexadecimal[j] = Hexadecimal[j] - 10 + 'A';
        else{
            hexadecimal[j] = Hexadecimal[j] + '0';
        }
        printf("%c",hexadecimal[j]);
    }
    printf("\n");
}

int Hexadecimal_to_Decimal(char hexadecimal[]){
	int i = 0;
	int decimal = 0;
	int temp;
	while(hexadecimal[i] != '\0'){
		if(hexadecimal[i] >= '0' && hexadecimal[i] <= '9')
			temp = hexadecimal[i] - '0';
		else if(hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F')
			temp = hexadecimal[i] -'A' + 10;
		else {
			printf("input error!\n");
			return 0;
		}
		decimal = decimal * 16 + temp;
		i++;
	}
	printf("%d\n",decimal);
	return decimal;
}


void Binary_to_Hexadecimal(int binary[],int length){
	Decimal_to_Hexadecimal(Binary_to_Decimal(binary,length));
}

void Hexadecimal_to_Binary(char hexadecimal[]){
	Decimal_to_Binary(Hexadecimal_to_Decimal(hexadecimal));
}

int test_switch(){
    int decimal1;
    int decimal2;
    char binary[100];
	char hexadecimal[100];
    int temp[100];
	int i;
cont:    
	printf("binary to decimal-----------input 1\n");
    printf("decimal to binary-----------input 2\n");
    printf("decimal to hexadecimal------input 3\n");
    printf("hexadecimal to decimal------input 4\n");
    printf("binary to hexadecimal-------input 5\n");
    printf("hexadecimal to binary-------input 6\n");
	printf("exit -----------------------input 7\n");
	scanf("%d",&i);
    switch(i){
    case 1:{
    	printf("please input a binary\n");
        scanf("%s",binary);
    	int i=0;
    	while(binary[i] != '\0'){
        	temp[i] = binary[i] -'0';
        	i++;
    	}
        printf("if unsigned input 1,else input 2'\n");
        scanf("%d",&i);
        if(i == 1)
    	   Binary_to_Decimal(temp,i);
        else if(i == 2)
            Binary_to_Decimal_signed(temp,i);
        else
            printf("input error\n");
		goto cont;
		break;
    }
    case 2:{
    	printf("please input a integer\n");
    	scanf("%d",&decimal1);
    	Decimal_to_Binary(decimal1);
		goto cont;
		break;
    }
    case 3:{
    	printf("please input a decimal\n");
    	scanf("%d",&decimal1);
    	Decimal_to_Hexadecimal(decimal1);
		goto cont;
		break;
    }
    case 4:{
    	printf("please input a hexadecimal\n");
		scanf("%s",hexadecimal);
		Hexadecimal_to_Decimal(hexadecimal);
		goto cont;
		break;
    }
    case 5:{
    	printf("please input a binary\n");
        scanf("%s",binary);
    	int i=0;
    	while(binary[i] != '\0'){
        	temp[i] = binary[i] -'0';
        	i++;
    	}
    	Binary_to_Hexadecimal(temp,i);
		goto cont;
		break;
    }
    case 6:{
    	printf("please input a hexadecimal\n");
		scanf("%s",hexadecimal);
		Hexadecimal_to_Binary(hexadecimal);
		goto cont;
		break;
    }
	case 7:{
		goto out;
		break;
    }
	}
out:
    return 0;
}
