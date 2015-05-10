/* 用bit位求并集或交集，针对不存在重复数的集合 */
/* 颜色color */
/* int a = '\0'相当于 int a = (int)'\0' = 0:查看acsii */


#include<stdio.h>
#include<string.h>

int rgb_len = 3;//默认值



typedef struct {
	//int rgb_len;
	//int rgb[rgb_len];
	int *rgb;
	char *color;
} COLOR_RGB;   //三原色结构体

typedef struct {
	COLOR_RGB *content;
	struct Node *next;
}Node;

typedef struct {
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
	head = current;//将current的初始地址保存在head里
	//Node node;
	//list->head = list->current = list->next = NULL;
	COLOR_RGB *buffer;
	int i;
	//printf("%d\n",strlen(color));
	//printf("%s\n",color[7]);
	M_LEN_COLOR(color,length->LEN_color);
	int temp = length->LEN_color;
	M_LEN_bit(temp,length->bitlen);
	//printf("%d,%d\n",length->LEN_color,length->bitlen);
	for(i=0;i<length->LEN_color;i++){
		Node *node = (Node *)malloc(sizeof(Node));
		current = node;
		color_rgb = (COLOR_RGB *)malloc(sizeof(COLOR_RGB));
		color_rgb->color = color[i];
		//color_rgb->rgb_len = length->bitlen;
		rgb_len = length->bitlen;
		//color_rgb = (COLOR_RGB *)malloc(sizeof(COLOR_RGB));
		int j;
		int k = i;
		int rgb_temp[length->LEN_color][rgb_len];
		for(j=rgb_len-1;j>=0;j--){
			rgb_temp[i][j] = k % 2;
			k = k / 2;
		}
		color_rgb->rgb = rgb_temp[i];
		//list->head = color_rgb;
		current->content = color_rgb;
		current->next = NULL;
		printf("%s : %d%d%d\n",current->content->color,*(current->content->rgb),*(current->content->rgb+1),*(current->content->rgb+2));
		current = current->next;
		
	}
	current = head;
	//printf("%s\n",current->content->color);
	// while(current){
		// printf("%s : %d%d%d\n",current->content->color,*(current->content->rgb),*(current->content->rgb+1),*(current->content->rgb+2));
		// current = current->next;
	// }
}

