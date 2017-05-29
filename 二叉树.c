/*
二叉树的创建 基本运算 先中后序遍历 层序遍历
容错机制不好不全 

*/

#include <stdio.h>
#include <stdlib.h>

#define		TRUE	1
#define		FALSE	0

//二叉树
typedef struct Node 
{
	char data;
	struct Node* LChild;
	struct Node* RChild;
}*BiTree, BiTNode;

//=====队列======= 层序遍历时需要用到 
typedef struct Node2{
	BiTree root;
	struct Node2 *next;
}linkQueueNode;

typedef struct{
	linkQueueNode *first;
	linkQueueNode *last;
}linkQueue;
//================ 

//函数声明 
BiTNode* visit(BiTree root); 			//二叉树的遍历 
void CreateBiTree(BiTree *root);		//扩展先序创建二叉树
void preOrder(BiTree root);				//先序遍历二叉树
void inOrder(BiTree root);				//中序遍历二叉树
void postOrder(BiTree root);			//后序遍历二叉树
int isEmpty(BiTree root);					//判断二叉树是否为空

int initQueue(linkQueue *Q);			//初始化队列
int empty(linkQueue *Q);					//判断队列是否为空
int enterQueue(linkQueue *Q, BiTree root);	// 入队列
int delQueue(linkQueue *Q, BiTree *root);		//删除队列 
int layerOrder(BiTree root);									//层序遍历 


//二叉树的遍历 
BiTNode* visit(BiTree root)
{
	if(root != NULL)
	{
		printf("%c", root->data);
		return root;
	}
	else
	{
		return NULL;
	}
}

//扩展先序创建二叉树
void CreateBiTree(BiTree *root)
{
	char ch;
//	ch = getchar();
	scanf("%c", &ch);
	getchar();
	if(ch == '#')
	{
		*root = NULL;
		return;
	}
	else
	{
		*root = (BiTree)malloc(sizeof(BiTNode));
		(*root)->data = ch;
		CreateBiTree(&((*root)->LChild));
		CreateBiTree(&((*root)->RChild));
	}
}

//先序遍历二叉树
void preOrder(BiTree root)
{
	if(root != NULL)
	{
		visit(root);
		preOrder(root->LChild);
		preOrder(root->RChild);
	}
}

//中序遍历二叉树
void inOrder(BiTree root)
{
	if(root != NULL)
	{
		inOrder(root->LChild);
		visit(root);
		inOrder(root->RChild);
	}
}

//后序遍历二叉树
void postOrder(BiTree root)
{
	if(root != NULL)
	{
		postOrder(root->LChild);
		postOrder(root->RChild);
		visit(root);
	}
}

//判断二叉树是否为空
int isEmpty(BiTree root){
	if(root == NULL){
		printf("二叉树为空...请重新输入，");
		return TRUE;
	}else{
		return FALSE; 
	}
}

//===============================================
//初始化队列 
int initQueue(linkQueue *Q){
//	printf("\n进入出事化队列\n");
	Q->first = (linkQueueNode *)malloc(sizeof(linkQueueNode));
	if(Q->first != NULL){
		Q->last = Q->first;
		Q->first->next = NULL;
		return (TRUE);
	}else{
		return FALSE;
	}
}

//判断队列是否为空
int empty(linkQueue *Q){
	if(Q->first->next == NULL){
//	printf("\n进入判断，队列为空\n");		
		return TRUE;
	}else{
//		printf("\n进入判断，队列不为空\n");	
		return FALSE;
	}
} 

// 入队列
int enterQueue(linkQueue *Q, BiTree root){
	
	linkQueueNode *newNode;
	newNode = (linkQueueNode *)malloc(sizeof(linkQueueNode));
	if(newNode != NULL){
//		printf("\n进入入队列\n");
		newNode->root = root;
		newNode->next = NULL;
		Q->last->next = newNode; 
		Q->last = newNode;
		return TRUE;
	}else{
		return FALSE;
	}
}

//删除队列 
int delQueue(linkQueue *Q, BiTree *root){
//	printf("\n进入删除队列\n");
	linkQueueNode *p, *data;
	if(Q->first == Q->last){
		return FALSE;
	}
	p = Q->first->next;
	Q->first->next = p->next;
	if(Q->last == p){
		Q->last = Q->first;
	}
	*root = p->root;
	free(p);
	return FALSE;
}

//层序遍历 
int layerOrder(BiTree root){
	linkQueue Q;
	BiTree p;
	initQueue(&Q);		//初始化二叉树为空 
	if(root == NULL){	
		printf("队列为空,退出！"); 
		return FALSE;
	}
	enterQueue(&Q, root);		//根节点入队 
	while(!empty(&Q)){		
//		printf("\n进入循环\n");
		delQueue(&Q, &p);			//队头元素出队并访问 
		visit(p);							//若p左孩子非空则继续入队 
		if(p->LChild){				//若p有孩子非空则继续入队 
			enterQueue(&Q, p->LChild);
		}
		if(p->RChild){
			enterQueue(&Q, p->RChild);
		}
	}
	printf("\n");
	return TRUE;
}
//=============================================== 


int main()
{
	BiTree root;
	int num, flag = 1;
	
	printf("菜单：\n0.退出\n1.建立二叉树存储结构\n2.求二叉树的先序遍历序列\n3.求二叉树的中序遍历序列\n4.求二叉树的后序遍历序列\n5.求二叉树的层序遍历序列\n");
	
	while(flag){
		printf("输入选项：");
		scanf("%d", &num);
		getchar();
		//注意对于输入字符会进入 0 选项，为何 
		switch(num){
			case 0:
				printf("退出\n");
				exit(0);
				break;
			
			case 1:
				printf("建立二叉树存储结构（请按扩展先序创建）:");
				CreateBiTree(&root);
				break;
			
			case 2:
				//还要判断二叉树是否为空 
				if(isEmpty(root)){
					break;
				}
				printf("先序遍历二叉树:");
				preOrder(root);
				printf("\n");
				break;
				
			case 3:
				if(isEmpty(root)){
					break;
				}
				printf("中序遍历二叉树:");
				inOrder(root);
				printf("\n");
				break;
				
			case 4:
				if(isEmpty(root)){
					break;
				}
				printf("后序遍历二叉树:");
				postOrder(root); 
				printf("\n");
				break;
			case 5:
				if(isEmpty(root)){
					break;
				}
				printf("层序遍历二叉树:");
				layerOrder(root);
				break;
				
			default:
				printf("输入选项错误，请重新");
				break;
		}
	}
	
	
	system("pause");
	return 0;
}
