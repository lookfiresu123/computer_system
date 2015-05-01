#include<stdio.h>
#include<string.h>
#include"little_endian.h"
#include"string.h"

void display_string(){
	const char *s = "abcdef";
	const char S[6] = {'a','b','c','d','e','f'};
	show_bytes((byte_pointer) s,strlen(s));
	show_bytes((byte_pointer) S,strlen(S));
}