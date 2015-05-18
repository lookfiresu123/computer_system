#include<stdio.h>
#include<math.h>

int fun1(unsigned word){
    return (int) ((word << 24) >> 24);
}

int fun2(unsigned word){
    return (((int)word << 24) >> 24);
}

unsigned short unsigned_32bit_to_16bit(unsigned int x){
    unsigned short y = x % (unsigned int)pow(2,16);//unsigned x for w bits --> for k bits <==> unsigned x mod pow(2,k)
    return y;
}

void test_shift_and_switch(){
    printf("input a unsigned word\n");
    unsigned word;
    unsigned int x;
    //scanf("%x",&word);//十六进制%x都是unsigned类型
    //printf("%x执行fun1后得：%x或%d\n",word,fun1(word),fun1(word));
    //printf("%x执行fun2后得：%x或%d\n",word,fun2(word),fun2(word));
    scanf("%x",&x);
    printf("%x执行unsigned_32bit_to_16bit后得： %hx或%hu\n",x,unsigned_32bit_to_16bit(x),unsigned_32bit_to_16bit(x));
}
