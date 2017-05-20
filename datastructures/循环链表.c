/*
循环单链表 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct cNode{
	char data;
	int len;	//表长 
	struct cNode *next;
}Node, *cNode;

cNode initCNode(cNode *L);				//初始化 
cNode createFromTail(cNode L);		//尾插法建立表
cNode searchAsNum(cNode L);				//按序号查找
cNode searchAsContent(cNode L);		//按内容查找
cNode insertCNode(cNode L);				//插入
cNode delList(cNode L);						//删除 
cNode print(cNode L);							//查看链表

//初始化 
cNode initCNode(cNode *L){
	(*L) = (cNode)malloc(sizeof(Node));
	(*L)->len = 0;
	(*L)->next = (*L);
	return (*L);
}

//尾插法建立表 
cNode createFromTail(cNode L){
	Node *s, *r;
	int i = 0, flag = 1;
	char data;
	
	r = L;
	printf("尾插法建立表,请输入数据并以'#'结束输入：\n");
	while(flag){
		printf("输入数据: ");
		scanf("%c", &data);
		getchar();
		if(data != '#'){
			s = (cNode)malloc(sizeof(Node));
			s->data = data;
			s->next = r->next;
			r->next = s;
			r = s;
			L->len++;
		}else{
			printf("结束输入...\n");
			flag = 0;
		}
	}
	r->next = L;
	print(L);
	return L;
}

//按序号查找
cNode searchAsNum(cNode L){
	int i, j;
	Node *p;
	
	p = L->next; 
	j = 1; 
	printf("\n请输入查找的序号: ");
	scanf("%d", &i);
	getchar();
	
	//查找的序号不可能为负 
	if(i <= 0){
		printf("输入不合法! \n");
		return NULL;
	}
	
	//单循环链表的到表尾的判断条件是 p != L 
	while((p != L) && (j < i)){
		p = p->next;
		j++;
	}
	
	if(j == i){
		//找到结点 
		printf("按序号查找成功, 序号 %d 的数据是 %c \n", i, p->data);
		return p;
	}else{
		//未找到 
		printf("按序号查找失败！未在表中找到数据！\n");
		return NULL;
	}
} 

//按内容查找
cNode searchAsContent(cNode L){
	Node *p;
	char data;
	int i = 1; 
	
	p = L->next;
	printf("\n请输入查找内容：");
	scanf("%c", &data);
	getchar();
	
	//遍历完表且未找到数据退出循环， 找到数据时退出函数 
	while(p != L){
		if(p->data == data){
			printf("按内容查找成功，第 %d 个位置的数据为 %c\n", i, p->data);
			return p;
		}
		p = p->next;
		i++;
	}
	
	//未找到数据
	if(p == L){
		printf("按内容查找失败！未在表中找到数据！\n");
	}
}  

//插入
cNode insertCNode(cNode L){
	Node *pre, *s;	
	int k, i;
	char data;
	pre = L->next;
	k = 1;
	printf("\n请输入你要插入的位置和内容(格式: address content)：");
	scanf("%d %c", &i, &data);
	getchar();
	
	//插入位置不可能为负 
	if(i <= 0){
		printf("插入失败！插入位置不合法！插入位置不能为负\n");
		return NULL;
	}
	
	////遍历完表且未找到插入位置(此时i大于表的长度) 或 找到插入位置时退出函数 退出循环
	while(pre != L && k < i - 1){
		pre = pre->next;
		k++;
	}
	
	if(pre == L){
		
		// 未找到插入位置(此时i大于表的长度)
		printf("插入失败！插入位置不合法！插入位置超出表的长度\n");
		return NULL;
	}else{
		
		//找到插入位置并插入数据 	，注意:pre指向插入位置的前一个结点  
		s = (cNode)malloc(sizeof(Node));
		s->data = data;
		s->next = pre->next;
		pre->next = s;
		L->len++; 
		printf("插入成功！");
		print(L);
		return L;
	}
} 

//删除 
cNode delList(cNode L){
	Node *pre, *r;
	int k = 0, i;
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
	while(pre->next != L && k < i - 1){
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
cNode print(cNode L){
	Node *p;
	int i = 0; 
	p = L->next;
	printf("查看链表数据为...\n");
	printf("共有 %d 个数据(注意序号是从头结点0开始，即第一个数据序号为 1)\n", L->len);
	for(; i < L->len; i++){
		printf("%c ", p->data);
		p = p->next;
	} 
	printf("\n\n");
	return L;
}

int main(void){
	Node *L;
	printf("===============================循环单链表=====================================\n");
	initCNode(&L);
	createFromTail(L);
	searchAsNum(L);
	searchAsContent(L);
	insertCNode(L);
	delList(L);
	printf("===============================循环单链表=====================================\n");
	return 0;
} 
