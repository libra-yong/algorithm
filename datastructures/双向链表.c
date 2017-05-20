/*
双向链表 
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct DNode{
	char data;
	int len;
	struct DNode *prior;
	struct DNode *next;
}DNode, *DList;

DList initDList(DList *L);
DList createFromTail(DList L);
DList searchAsNum(DList L);
DList searchAsContent(DList L);
DList insertDList(DList L);
DList delDList(DList L);
DList print(DList L);

//初始化
DList initDList(DList *L){
	(*L) = (DList)malloc(sizeof(DNode));
	(*L)->len = 0;
	(*L)->prior = (*L);
	(*L)->next = (*L);
	return *L;
} 

//尾插法创建 
DList createFromTail(DList L){
	DNode *s, *r;
	int flag = 1;
	char data;
	r = L;
	printf("尾插法建立表,请输入数据并以'#'结束输入：\n");
	while(flag){
		printf("输入数据: ");
		scanf("%c", &data);
		getchar();
		if(data == '#'){
			//若输入 # 则退出 
			flag = 0;
		}else{
			s = (DList)malloc(sizeof(DNode));
			s->data = data;
			s->prior = r;
			s->next = L;
			r->next = s;
			r = s;
			L->prior = r;
			(L->len)++; 
			flag = 1;
		}
	}
	printf("结束输入...\n");
	print(L);
	return L;
}

//按序号查找
DList searchAsNum(DList L){
	int i, j;
	DNode *p;
	
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
	while((p->next != L) && (j < i)){
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
DList searchAsContent(DList L){
	DNode *p;
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
DList insertDList(DList L){
	DNode *pre, *s;
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
		
		//找到插入位置并插入数据 ,注意:pre指向插入位置的前一个结点 
		s = (DNode*)malloc(sizeof(DNode));
		s->data = data;
		
		s->next = pre->next;
		pre->next->prior = s;
		s->prior = pre; 
		pre->next = s;
		
		L->len++;
		printf("插入成功！");
		print(L);
		return L;
	}
}  

//删除 
DList delDList(DList L){
	DNode *p;
	int k = 1, i;
	p = L->next;
	printf("请输入删除的数据的位置(格式：address)：");
	scanf("%d", &i); 
	getchar();
	
	//删除的位置必须合法 
	if(i > L->len || i<= 0){
		printf("删除的位置超出了链表的长度!\n");
		return;
	}
	
	// 找到删除位置退出
	while(p != L && k < i){
		p = p->next;
		k++;
	}
	
	//删除操作 
	p->next->prior = p->prior;
	p->prior->next = p->next;
	//上面两步可以互换顺序 
	
	free(p);
	L->len--;
	printf("删除成功！\n"); 
	print(L);
	return L;
} 

//查看表 
DList print(DList L){
	DNode *p;
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
	DNode *L;
	printf("===============================双向链表=====================================\n");
	initDList(&L);
	createFromTail(L);
	searchAsNum(L);
	searchAsContent(L);
	insertDList(L);
	delDList(L);
	printf("===============================双向链表=====================================\n");
	return 0;
}
