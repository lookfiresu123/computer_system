#include<stdio.h>

int fun1(unsigned word){
    return (int) ((word << 24) >> 24);
}

int fun2(unsigned word){
    return (((int)word << 24) >> 24);
}

void test_shift_and_switch(){
    printf("input a unsigned word\n");
    unsigned word;
    scanf("%x",&word);//十六进制%x都是unsigned类型
    printf("%x执行fun1后得：%x或%d\n",word,fun1(word),fun1(word));
    printf("%x执行fun2后得：%x或%d\n",word,fun2(word),fun2(word));
}
