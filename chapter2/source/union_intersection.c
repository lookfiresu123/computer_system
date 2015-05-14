/* 用bit位求并集或交集，针对不存在重复数的集合 */
/* 颜色color */
/* int a = '\0'相当于 int a = (int)'\0' = 0:查看acsii */


#include<stdio.h>
#include<string.h>

int rgb_len = 3;//默认值



typedef struct COLOR_RGB{
	//int rgb_len;
	//int rgb[rgb_len];
	int *rgb;
	char *color;
} COLOR_RGB;   //三原色结构体

typedef struct Node{
	COLOR_RGB *content;
	struct Node *next;
}Node;

typedef struct LENGTH{
	int LEN_color;//color的长度
	int bitlen;//位的长度
} LENGTH;    //长度

const char *color[]= {"black","blue","green","cyan","red","magenta","yellow","white"};

#define M_LEN_bit(len,i) do {	len % 2;   \
							len = len / 2;   \
							i++;     \
						}while(len != 0);i--;
						
#define M_LEN_COLOR(color,i) while(color[i]){ i=i+1; } i--;

void Union_intersection(){
	/* 定义并初始化8种三原色结构体 */
	LENGTH *length = (LENGTH *)malloc(sizeof(LENGTH));
	length->LEN_color = 0;
	length->bitlen = 0;
	COLOR_RGB *color_rgb;
	Node *current,*head;
	head = (Node *)malloc(sizeof(Node));
	current = head;//将head的初始地址保存在current里,head为头节点，内容为空，第一个颜色的节点存在head->next中
	COLOR_RGB *buffer;
	int i;
	M_LEN_COLOR(color,length->LEN_color);
	int temp = length->LEN_color;
	M_LEN_bit(temp,length->bitlen);
	Node node[length->LEN_color];
	for(i=0;i<length->LEN_color;i++){
		current->next = &node[i];		
		current = current->next;		
		color_rgb = (COLOR_RGB *)malloc(sizeof(COLOR_RGB));
		color_rgb->color = color[i];
		rgb_len = length->bitlen;
		int j;
		int k = i;
		int rgb_temp[length->LEN_color][rgb_len];
		for(j=rgb_len-1;j>=0;j--){
			rgb_temp[i][j] = k % 2;
			k = k / 2;
		}
		color_rgb->rgb = (int *)malloc(rgb_len*sizeof(int));
		for(j=0;j<rgb_len;j++){
			*(color_rgb->rgb+j) = rgb_temp[i][j];
		}
		current->content = color_rgb;
		current->next = NULL;		
	}
	current = head->next;
	
	printf("输入两种颜色\n");
	char color1[10];
	char color2[10];
	scanf("%s",color1);
	scanf("%s",color2);
	i=0;
	
	Node *p1;
	Node *p2;
	
	while(current){
		i=0;
		int flag_temp = 1;
		while(color1[i] != '\0'){
			if(color1[i] != *(current->content->color+i)){
				flag_temp = 0;
				break;
			}
			i++;
		}
		if(flag_temp == 1){
			p1 = current;
		}
		i=0;
		flag_temp = 1;
		while(color2[i] != '\0'){
			if(color2[i] != *(current->content->color+i)){
				flag_temp = 0;
				break;
			}
			i++;
		}
		if(flag_temp == 1){
			p2 = current;
		}
		//i=0;
		current = current->next;
	}
	i = 0;
	//Node *result = (Node *)malloc(sizeof(Node));
	int result_rgb[rgb_len];
	//result->content->rgb = (int *)malloc(rgb_len*sizeof(int));
	//result->next = NULL;
	for(i=0;i<rgb_len;i++){
		result_rgb[i] = *(p1->content->rgb+i) | *(p2->content->rgb+i);
	}
	current = head->next;
	//printf("%s\n",current->content->color);
	int flag = 1;
	while(current){
		for(i=0;i<rgb_len;i++){
			//printf("%d",*(current->content->rgb+i));
			if(result_rgb[i] != *(current->content->rgb+i)){
				flag = 0;
				break;
			}
		}
		//printf("\n");
		if(flag == 1){
			//result->content->color = current->content->color;
			break;
		}
		else{
			flag = 1;
			current = current->next;
		}
	}
	printf("%s\n",current->content->color);
	
}

