#include<stdio.h>

//int array_size = 32;
struct tag
{
	int binary_signed[32];
	unsigned int binary_unsigned[32];
};

int pow_vary(int x,int y);
struct tag Decimal_to_Binary_signed(int decimal);
struct tag Decimal_to_Binary_unsigned(unsigned int decimal);
int Binary_to_Decimal_another_signed(int binary[],int length);/* one's complement encodings */
void Decimal_to_Binary(unsigned int decimal);
unsigned int Binary_to_Decimal(unsigned int binary[],int length);
int Binary_to_Decimal_signed(int binary[],int length);/* two's complement encodings */
int Binary_to_Decimal_magnitude_signed(int binary[],int length);/* sign-magnitude encodings */
void Decimal_to_Hexadecimal(int decimal);
int Hexadecimal_to_Decimal(char hexadecimal[]);
void Binary_to_Hexadecimal(int binary[],int length);
void Hexadecimal_to_Binary(char hexadecimal[]);
int test_switch();
void test_convert();