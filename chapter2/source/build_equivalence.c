#include<stdio.h>

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