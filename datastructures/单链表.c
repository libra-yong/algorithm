/*
线性表的链式存储 
基本操作：查找，插入，删除
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
	char ch;
	int len;	//表长度 
	struct Node *next;
}Node, *linkList;



void initList(linkList *L);							//初始化链表 
linkList cteateFromeHead(linkList L);		//头插法建立表
linkList createFromTail(linkList L);		//尾插法建立表 
linkList getAsNum(linkList L);					//按序号查找 
linkList getAsContent(linkList L);			//按内容查找
linkList insertList(linkList L);				//插入
linkList delList(linkList L);								//删除
linkList print(linkList L);							//查看链表
 
//初始化链表 
void initList(linkList *L){
	(*L) = (linkList)malloc(sizeof(Node));
	(*L)->len = 0;
	(*L)->next = NULL;
}

//头插法建立表 
linkList cteateFromeHead(linkList L){
	Node *s;
	char ch;
	int flag = 1;
	printf("头插法建立表,请输入数据并以'#'结束输入：\n"); 
	while(flag){
		printf("输入数据: ");
		scanf("%c", &ch);
		getchar();
		if(ch == '#'){
			//若输入 # 则退出 
			flag = 0;
		}else{
			s = (linkList)malloc(sizeof(Node));	
			s->ch = ch; 
			s->next = L->next;
			L->next = s;
			(L->len)++; 
			flag = 1;
		}
	}
	print(L);
	return L;
}

//尾插法建立表 
linkList createFromTail(linkList L){
	Node *s, *r;	//r指针始终指向链表尾部 
	char ch;
	int flag = 1;
	r = L;
	printf("尾插法建立表,请输入数据并以'#'结束输入：\n");
	while(flag){
		printf("输入数据: ");
		scanf("%c", &ch);
		getchar();
		if(ch == '#'){
			//若输入 # 则退出 
			flag = 0;
			r->next = NULL;
		}else{
			s = (linkList)malloc(sizeof(Node));
			s->ch = ch;
			r->next = s;
			r = s;
			(L->len)++; 
			flag = 1;
		}
	} 
	print(L);
	return L;
} 

//按序号查找 
linkList getAsNum(linkList L){
	int i, j;
	Node *p;
	
	p = L; 
	j = 0; 
	printf("\n请输入查找的序号: ");
	scanf("%d", &i);
	getchar();
	
	//查找的序号不可能为负 
	if(i <= 0){
		printf("输入不合法! \n");
		return NULL;
	}
	
	//退出情况有两种：表遍历完毕没有找到数据 或 p指针指向目标结点 
	while((p->next != NULL) && (j < i)){
		p = p->next;
		j++;
	}
	
	if(j == i){
		//找到结点 
		printf("按序号查找成功, 序号 %d 的数据是 %c \n", i, p->ch);
		return p;
	}else{
		//未找到 
		printf("按序号查找失败！未在表中找到数据！\n");
		return NULL;
	}
}

//按内容查找
linkList getAsContent(linkList L){
	Node *p;
	char ch;
	int i = 1; 
	
	p = L->next;
	printf("\n请输入查找内容：");
	scanf("%c", &ch);
	getchar();
	
	//遍历完表且未找到数据退出循环， 找到数据时退出函数 
	while(p != NULL){
		if(p->ch == ch){
			printf("按内容查找成功，第 %d 个位置的数据为 %c\n", i, p->ch);
			return p;
		}
		p = p->next;
		i++;
	}
	
	//未找到数据
	if(p == NULL){
		printf("按内容查找失败！未在表中找到数据！\n");
	}
} 

//插入
linkList insertList(linkList L){
	Node *pre, *s;
	int k, i;
	char ch;
	pre = L;
	k = 0;
	printf("\n请输入你要插入的位置和内容(格式: address content)：");
	scanf("%d %c", &i, &ch);
	getchar();
	
	//插入位置不可能为负 
	if(i <= 0){
		printf("插入失败！插入位置不合法！插入位置不能为负\n");
		return NULL;
	}
	
	////遍历完表且未找到插入位置(此时i大于表的长度) 或 找到插入位置时退出函数 退出循环
	while(pre != NULL && k < i - 1){
		pre = pre->next;
		k++;
	}
	
	if(pre == NULL){
		
		// 未找到插入位置(此时i大于表的长度)
		printf("插入失败！插入位置不合法！插入位置超出表的长度\n");
		return NULL;
	}else{
		
		//找到插入位置并插入数据 
		s = (linkList)malloc(sizeof(Node));
		s->ch = ch;
		s->next = pre->next;
		pre->next = s;
		L->len++;
		printf("插入成功！");
		print(L);
		return L;
	}
} 

//删除
linkList delList(linkList L){
	Node *pre, *r;
	int k = 0, i;
	char *ch;
	pre = L;
	printf("请输入删除的数据的位置(格式：address)：");
	scanf("%d", &i); 
	getchar();
	
	//删除的位置必须合法 
	if(i > L->len || i<= 0){
		printf("删除的位置超出了链表的长度!\n");
		return;
	}
	
	// 找到删除位置退出
	while(pre->next != NULL && k < i - 1){
		pre = pre->next;
		k++;
	}
	
	//删除操作 
	r = pre->next;
	pre->next = r->next;
	free(r);
	L->len--;
	printf("删除成功！\n"); 
	print(L);
	return L;
} 

//查看链表 
linkList print(linkList L){
	Node *p;
	int i = 0; 
	p = L->next;
	printf("==============查看链表数据为==============\n");
	printf("共有 %d 个数据(注意序号是从头结点0开始，即第一个数据序号为 1)\n", L->len);
	for(; i < L->len; i++){
		printf("%c ", p->ch);
		p = p->next;
	} 
	printf("\n\n");
	return L;
}

int main(void){
	Node *L;
	initList(&L);
	
	//头插法 
//	cteateFromeHead(L);

	//尾插法 
	createFromTail(L);		 
	getAsNum(L);					 
	getAsContent(L);			
	insertList(L);				
	delList(L);		
	return 0;
} 
