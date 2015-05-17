/* switch from decimal to hexadecimal and binary */
#include<stdio.h>
#include<math.h>
#include"../header/switch.h"

int array_size = 32;

struct tag convert;

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
        //convert.binary_unsigned[array_size-j-1] = binary[j];
        printf("%d",binary[j]);
    }
    printf("\n");
}

struct tag Decimal_to_Binary_unsigned(unsigned int decimal){
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
        convert.binary_unsigned[array_size-j-1] = binary[j];
        printf("%d",binary[j]);
    }
    printf("\n");
    return convert;
}

struct tag Decimal_to_Binary_signed(int decimal){
    int binary[array_size];
    //initial
    int i=0;
    int flag = 1;
    if(decimal < 0){
        flag = 0;
        decimal = 0 - decimal;
        printf("%d\n",decimal);
    }
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
    if(flag == 0){
        binary[array_size-1] = 1;
        for(j=array_size-2;j>=0;j--)
            binary[j] = 1 ^ binary[j];
    }
    // for(j=array_size-1;j>=0;j--)
    //     printf("%d",binary[j]);
    // printf("\n");
    j = 0;
    while(binary[j]){
        binary[j] = 1 ^ binary[j];
        j++;
    }
    binary[j] = 1 ^ binary[j];
    for(j=array_size-1;j>=0;j--){
        convert.binary_signed[array_size-j-1] = binary[j];
        printf("%d",binary[j]);
    }
    printf("\n");
    return convert;
}

/* two's complement encodings */
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

/* one's complement encodings --> +0 = 00...0, -0 = 11...1 */
int Binary_to_Decimal_another_signed(int binary[],int length){
    int Decimal = 0;
    int i,j;
    int temp = 0 - binary[length-1] * (pow_vary(2,length-1) - 1);
    for(i=0;i<length-1;i++)
        Decimal = Decimal + binary[i] * pow_vary(2,i);
    Decimal = temp + Decimal;
    printf("%d\n",Decimal);
    return Decimal;
}

/* sign-magnitude encodings --> +0 = 00...0, -0 = 10...0*/
int Binary_to_Decimal_magnitude_signed(int binary[],int length){
    int Decimal = 0;
    int i,j;
    for(i=0;i<length-1;i++)
        Decimal = Decimal + binary[i] * pow_vary(2,i);
    if(binary[i] == 1)
        Decimal = 0 - Decimal;
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
    printf("%u\n",Decimal);
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

//signed to unsigned


void Binary_to_Hexadecimal(int binary[],int length){
	Decimal_to_Hexadecimal(Binary_to_Decimal(binary,length));
}

void Hexadecimal_to_Binary(char hexadecimal[]){
	Decimal_to_Binary(Hexadecimal_to_Decimal(hexadecimal));
}

void test_convert(){
    int i;
    printf("input 1 for signed to unsigned, 2 for unsigned to signed\n");
    scanf("%d",&i);
    switch(i){
    case 1:
        goto signed_to_unsigned;
        break;
    case 2:
        goto unsigned_to_signed;
        break;
    default:
        printf("input error\n");
        goto end;
        break;
    }
    struct tag mid_convert;
signed_to_unsigned:
    printf("input a decimal\n");
    int decimal_signed;
    //struct tag mid_convert;
    scanf("%d",&decimal_signed);
    mid_convert = Decimal_to_Binary_signed(decimal_signed);
    for(i=0;i<array_size;i++)
        mid_convert.binary_unsigned[i] = (unsigned int)mid_convert.binary_signed[i];
    Binary_to_Decimal(mid_convert.binary_unsigned,array_size);
    goto end;
unsigned_to_signed:
    printf("input a decimal\n");
    unsigned int decimal_unsigned;
    //struct tag mid_convert;
    scanf("%d",&decimal_unsigned);
    mid_convert = Decimal_to_Binary_unsigned(decimal_unsigned);
    for(i=0;i<array_size;i++)
        mid_convert.binary_signed[i] = (int)mid_convert.binary_unsigned[i];
    Binary_to_Decimal_signed(mid_convert.binary_signed,array_size);
    goto end;
end:
    printf("good bye\n");
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
