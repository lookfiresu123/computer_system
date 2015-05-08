/* 用bit位求并集或交集，针对不存在重复数的集合 */
/* 范围为：0~9,'a'~'z','A'~'Z' */

#include<stdio.h>

int LEN = 62; //paramters的长度和交并集的总位数

typedef struct{
	char ch;
	int pos;
}CODE;

CODE paramters[] = {
	{'0',0}, {'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9},  \
	{'a',10},{'b',11},{'c',12},{'d',13},{'e',14},{'f',15},{'g',16},{'h',17},{'i',18},{'j',19},{'k',20},{'l',21},{'m',22},{'n',23},   \
	{'o',24},{'p',25},{'q',26},{'r',27},{'s',28},{'t',29},{'u',30},{'v',31},{'w',32},{'x',33},{'y',34},{'z',35},   \
	{'A',36},{'B',37},{'C',38},{'D',39},{'E',40},{'F',41},{'G',42},{'H',43},{'I',44},{'J',45},{'K',46},{'L',47},{'M',48},{'N',49},   \
	{'O',50},{'P',51},{'Q',52},{'R',53},{'S',54},{'T',55},{'U',56},{'V',57},{'W',58},{'X',59},{'Y',60},{'Z',61}
};

int Transation_Single(char ch){
	int pos;
	int i;
	for(i=0;i<LEN;i++){
		if(paramters[i].ch == ch)
			pos = paramters[i].pos;
	}
	return pos;
}

int Transation(int vector[]){
	char c;
	while('\n' != (c = getchar())){
		if(c != ' ' && c != ',')
			vector[Transation_Single(c)] = 1; 
	}
	return 0;
}

int union_intersection_advance(){
	int vector1[LEN],vector2[LEN];
	int Union[LEN],Intersection[LEN];
	char result_Union[LEN+1];//保留一位给'\0'
	char result_Intersection[LEN+1];//保留一位给'\0'
	//initial
	int i;
	for(i=0;i<LEN;i++)
		vector1[i] = vector2[i] = 0;
	
	printf("输入两个集合\n");
	
	//转换成pos
	Transation(vector1);
	Transation(vector2);
	
	//&或|操作
	for(i=0;i<LEN;i++){
		Union[i] = vector1[i] | vector2[i];
		Intersection[i] = vector1[i] & vector2[i];
	}
	
	//根据parameters找ch
	int pos_Union = 0;
	int pos_Intersection = 0;
	for(i=0;i<LEN;i++){
		if(Union[i] == 1){
			//在parameters中找i对应的ch
			int j;
			for(j=0;j<LEN;j++){
				if(paramters[j].pos == i){
					result_Union[pos_Union] = paramters[j].ch;
					pos_Union++;
					break;
				}
			}
		}
	}
	for(i=0;i<LEN;i++){
		if(Intersection[i] == 1){
			//在parameters中找i对应的ch
			int j;
			for(j=0;j<LEN;j++){
				if(paramters[j].pos == i){
					result_Intersection[pos_Intersection] = paramters[j].ch;
					pos_Intersection++;
					break;
				}
			}
		}
	}
	result_Union[pos_Union] = '\0';
	result_Intersection[pos_Intersection] = '\0';
	
	printf("并集为：{ ");
	i = 0;
	while(result_Union[i] != '\0'){
		printf("%c ",result_Union[i]);
		i++;
	}
	printf("}\n");
	
	printf("交集为：{ ");
	i = 0;
	while(result_Intersection[i] != '\0'){
		printf("%c ",result_Intersection[i]);
		i++;
	}
	printf("}\n");
	
	
	return 0;
}


