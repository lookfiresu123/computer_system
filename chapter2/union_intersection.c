/* 用bit位求并集或交集，针对不存在重复数的集合 */
/* 0,1,...,9 */
/* int a = '\0'相当于 int a = (int)'\0' = 0:查看acsii */


#include<stdio.h>

int Input(int set[]){
	//printf("input a set of number\n");
	char a;
	//int set[100];
	int i=0;
	while(1){
cont:
		a = getchar();
		if((a != '\n') && (a != ' ') && (a != ',')){
			set[i] = a - '0';
			// printf("set[%d] = %d\n",i,set[i]);
			i++;
		}
		if(a == '\n')
			goto out;
		if(a == ' ' || a== ',')
			goto cont;
	}
out:
	set[i] = -1;
	// int j=0;
	// while(set[j] != '\0'){
		// printf("%d",set[j]);
		// j++;
	// }
	// printf("\n");
	return 0;
}

void Union_intersection(){
	int u1[100],u2[100];
	int set1[10],set2[10];
	int ret_union[10];
	int ret_intersection[10];
	printf("input a set of number\n");
	Input(u1);
	printf("input another set of number\n");
	Input(u2);
	int i = 0;
	
	// while(u1[i] != -1){
		// printf("%d",u1[i]);
		// i++;
	// }
	// printf("\n");
	// i=0;
	// while(u2[i] != -1){
		// printf("%d",u2[i]);
		// i++;
	// }
	// printf("\n");
	// i=0;

	//初始化
	for(i=0;i<10;i++)
		set1[i] = set2[i] = 0;
		
	i = 0;	
	while(u1[i] != -1){
		set1[u1[i]] = 1;
		i++;
	}
	i = 0;
	while(u2[i] != -1){
		set2[u2[i]] = 1;
		i++;
	}
	
	// printf("set1 : \n");
	// for(i=0;i<10;i++)
		// printf("%d",set1[i]);
	// printf("\n");
	// printf("set2 : \n");
	// for(i=0;i<10;i++)
		// printf("%d",set2[i]);
	// printf("\n");
	
	//按位与和或
	for(i=0;i<10;i++){
		ret_union[i] = set1[i] | set2[i];
		ret_intersection[i] = set1[i] & set2[i];
	}
	
	printf("并集为：{ ");
	for(i=0;i<10;i++){
		if(ret_union[i] == 1)
			printf("%d ",i);
	}
	printf("}\n");
	
	printf("交集为：{ ");
	for(i=0;i<10;i++){
		if(ret_intersection[i] == 1)
			printf("%d ",i);
	}
	printf("}\n");
	
	
	
	
	
}

