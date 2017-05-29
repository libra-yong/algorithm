/*
�������Ĵ��� �������� ���к������ �������
�ݴ���Ʋ��ò�ȫ 

*/

#include <stdio.h>
#include <stdlib.h>

#define		TRUE	1
#define		FALSE	0

//������
typedef struct Node 
{
	char data;
	struct Node* LChild;
	struct Node* RChild;
}*BiTree, BiTNode;

//=====����======= �������ʱ��Ҫ�õ� 
typedef struct Node2{
	BiTree root;
	struct Node2 *next;
}linkQueueNode;

typedef struct{
	linkQueueNode *first;
	linkQueueNode *last;
}linkQueue;
//================ 

//�������� 
BiTNode* visit(BiTree root); 			//�������ı��� 
void CreateBiTree(BiTree *root);		//��չ���򴴽�������
void preOrder(BiTree root);				//�������������
void inOrder(BiTree root);				//�������������
void postOrder(BiTree root);			//�������������
int isEmpty(BiTree root);					//�ж϶������Ƿ�Ϊ��

int initQueue(linkQueue *Q);			//��ʼ������
int empty(linkQueue *Q);					//�ж϶����Ƿ�Ϊ��
int enterQueue(linkQueue *Q, BiTree root);	// �����
int delQueue(linkQueue *Q, BiTree *root);		//ɾ������ 
int layerOrder(BiTree root);									//������� 


//�������ı��� 
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

//��չ���򴴽�������
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

//�������������
void preOrder(BiTree root)
{
	if(root != NULL)
	{
		visit(root);
		preOrder(root->LChild);
		preOrder(root->RChild);
	}
}

//�������������
void inOrder(BiTree root)
{
	if(root != NULL)
	{
		inOrder(root->LChild);
		visit(root);
		inOrder(root->RChild);
	}
}

//�������������
void postOrder(BiTree root)
{
	if(root != NULL)
	{
		postOrder(root->LChild);
		postOrder(root->RChild);
		visit(root);
	}
}

//�ж϶������Ƿ�Ϊ��
int isEmpty(BiTree root){
	if(root == NULL){
		printf("������Ϊ��...���������룬");
		return TRUE;
	}else{
		return FALSE; 
	}
}

//===============================================
//��ʼ������ 
int initQueue(linkQueue *Q){
//	printf("\n������»�����\n");
	Q->first = (linkQueueNode *)malloc(sizeof(linkQueueNode));
	if(Q->first != NULL){
		Q->last = Q->first;
		Q->first->next = NULL;
		return (TRUE);
	}else{
		return FALSE;
	}
}

//�ж϶����Ƿ�Ϊ��
int empty(linkQueue *Q){
	if(Q->first->next == NULL){
//	printf("\n�����жϣ�����Ϊ��\n");		
		return TRUE;
	}else{
//		printf("\n�����жϣ����в�Ϊ��\n");	
		return FALSE;
	}
} 

// �����
int enterQueue(linkQueue *Q, BiTree root){
	
	linkQueueNode *newNode;
	newNode = (linkQueueNode *)malloc(sizeof(linkQueueNode));
	if(newNode != NULL){
//		printf("\n���������\n");
		newNode->root = root;
		newNode->next = NULL;
		Q->last->next = newNode; 
		Q->last = newNode;
		return TRUE;
	}else{
		return FALSE;
	}
}

//ɾ������ 
int delQueue(linkQueue *Q, BiTree *root){
//	printf("\n����ɾ������\n");
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

//������� 
int layerOrder(BiTree root){
	linkQueue Q;
	BiTree p;
	initQueue(&Q);		//��ʼ��������Ϊ�� 
	if(root == NULL){	
		printf("����Ϊ��,�˳���"); 
		return FALSE;
	}
	enterQueue(&Q, root);		//���ڵ���� 
	while(!empty(&Q)){		
//		printf("\n����ѭ��\n");
		delQueue(&Q, &p);			//��ͷԪ�س��Ӳ����� 
		visit(p);							//��p���ӷǿ��������� 
		if(p->LChild){				//��p�к��ӷǿ��������� 
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
	
	printf("�˵���\n0.�˳�\n1.�����������洢�ṹ\n2.��������������������\n3.��������������������\n4.��������ĺ����������\n5.��������Ĳ����������\n");
	
	while(flag){
		printf("����ѡ�");
		scanf("%d", &num);
		getchar();
		//ע����������ַ������ 0 ѡ�Ϊ�� 
		switch(num){
			case 0:
				printf("�˳�\n");
				exit(0);
				break;
			
			case 1:
				printf("�����������洢�ṹ���밴��չ���򴴽���:");
				CreateBiTree(&root);
				break;
			
			case 2:
				//��Ҫ�ж϶������Ƿ�Ϊ�� 
				if(isEmpty(root)){
					break;
				}
				printf("�������������:");
				preOrder(root);
				printf("\n");
				break;
				
			case 3:
				if(isEmpty(root)){
					break;
				}
				printf("�������������:");
				inOrder(root);
				printf("\n");
				break;
				
			case 4:
				if(isEmpty(root)){
					break;
				}
				printf("�������������:");
				postOrder(root); 
				printf("\n");
				break;
			case 5:
				if(isEmpty(root)){
					break;
				}
				printf("�������������:");
				layerOrder(root);
				break;
				
			default:
				printf("����ѡ�����������");
				break;
		}
	}
	
	
	system("pause");
	return 0;
}
