/*
线性表的顺序存储 
基本操作：查找，插入，删除 
*/

#include<stdio.h>
#include<string.h>

#define MAXSIZE 100			 
#define OK 1
#define ERROR -1

typedef struct{
	char data[MAXSIZE];	
	int len;	//数据长度 
}List;

List* initList(List *L);													//初始化 
int getAsNum(List L, int num);										//按序号查找 
int getAsContent(List L, char content);						//按内容查找
int insertList(List *L, int i, char content);			//插入，在元素之前插入		
int deleteList(List *L, int i, char *content);		//删除
void print(List *L);															//打印

//初始化顺序表 
List* initList(List *L){
	int num, i;
	char ch;
	//输入顺序表长度
	printf("请输入顺序表长度（0<len<100): ");
	scanf("%d", &num);
	L->len = num;
	
	//输入数据 
	for(i = 0; i < L->len; i++){
		getchar();
		printf("请输入第 %d 个数：", i);
		scanf("%c", &ch);
		L->data[i] = ch;
	}
	return L;
}

//按序号查找 
int getAsNum(List L, int num){
	if(num < 0 || num > L.len - 1){
		printf("查找失败，位置 %d 超过链表长度！\n\n", num);
		return ERROR;
	}else{
		printf("按序号查找成功，第 %d 个位置元素为 %c \n\n", num, L.data[num]);
		return num;
	}
}

//按内容查找
int getAsContent(List L, char content){
	unsigned int i = 0; 
	while(i >= 0 || i <= L.len - 1){
		//顺序扫描表，找到对应元素，或者扫描完则退出 
		if(L.data[i] != content){
			i++;
		}else{ 
			break;
		}
	}
	if(i <= L.len - 1){
		//找到则输出并返回序号 
		printf("按内容查找成功，第 %d 个位置元素为 %c \n\n", i, L.data[i]);
		return i;
	}else{
		//未找到 
		printf("查找失败，没有你所找的元素！\n\n");
		return ERROR; 
	}
}

//插入，在元素之前插入
int insertList(List *L, int i, char content){
	int k;
	
	//插入的位置不在表的范围 
	if(i < 0 || i >= L->len){
		printf("插入位置不合法！\n\n");
		return ERROR;
	}
	
	//考虑表满的情况 
	if(L->len == MAXSIZE){
		printf("表已满！无法插入！\n\n");
		return ERROR;
	}else if(i >= 0 && i <= L->len - 1){
		
		//插入位置后的元素向后移动 
		for(k = L->len - 1; k >= i; k--){
			L->data[k+1] = L->data[k];
		}
		L->data[i] = content;
		//表长度加一 
		L->len++;
		printf("插入成功！\n\n");
		print(L);
		return OK;
	}
} 

//删除 
int deleteList(List *L, int i, char *content){
	int k;
	
	//删除位置不合法则推出 
	if(i < 0 || (i >= L->len)){
		printf("删除位置不合法！\n\n");
		return ERROR;
	}
	
	//删除的表已空 
	if(L->len == 0){
		printf("表已空！\n\n");
		return ERROR;
	}else{
		*content = L->data[i];
		
		//前移 
		for(k = i; k <= L->len - 2; k++){
			L->data[k] = L->data[k+1];
		}
		
		//删除成功后表长度减一 
		L->len--;
		printf("删除成功！\n\n");
		print(L);
		return OK;
	}
}

//打印 
void print(List *L){
	int i; 
	printf("===================顺序表如下===================\n");
	printf("共有 %d 个数据: ", L->len); 
	for(i = 0; i < L->len; i++){
		printf("%c ", L->data[i]);
	}
	printf("\n");
}

int main(void){
	List L;
	int i, num, length, flag = 1;
	char ch, cha; 
	
	//初始化 
	initList(&L); 
	print(&L);
	
	//按序号查找 
	printf("请输入你要查找的元素序号：");
	scanf("%d", &num);
	getchar();
	getAsNum(L, num);
	
	//按内容查找 
	printf("请输入你要查找的元素的内容：");
	scanf("%c", &ch);
	getchar();
	getAsContent(L, ch);
	
	//插入元素 
	printf("请输入你要插入的内容(格式:addr_num data_char)：");
	scanf("%d %c", &num, &ch);
	getchar();
	insertList(&L, num, ch);
	
	//删除元素 
	printf("请输入你要删除的位置(格式:addr_num)：");
	scanf("%d", &num);
	getchar();
	deleteList(&L, num, &cha);	
	
	return 0;
} 
