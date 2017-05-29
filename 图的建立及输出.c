/*
ͼ�Ĵ洢�ṹ
�ڽӾ����ʾ�� 

�ڽ�����Ȩͼʱ�޷�����ַ������������ͼ�����ֱ���һ�����������ǽ����ִ����ϲ�������û���ݴ���� 
*/

#include <stdio.h> 
#include<stdlib.h>

#define 	MAX_VERTEX_NUM 		20			//��ඥ����� 
#define 	INFINITY 			32678		//��ʾ����ֵ�������� 
#define OK 1
#define Error -1
#define MAX 100

typedef enum{DG, DN, UDG, UDN} GraphKind;	//ͼ�����ࣺ����ͼ��������������ͼ�������� 

//�����Ȩֵ 
typedef struct ArcNode
{
	int adj;		//������Ȩͼ����1��0��ʾ�Ƿ����ڣ��Դ�Ȩͼ����ΪȨֵ����
	int info;
}ArcNode;

//����ͼ���� 
typedef struct 
{
	char vertex[MAX_VERTEX_NUM];		//�������� 
	ArcNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];	//�ڽӾ��� 
	int vexnum, arcnum;		//ͼ�Ķ������ͻ��� 
	GraphKind kind;			//ͼ�������־ 
}AdjMatrix;

void init(AdjMatrix *G, GraphKind kind);	//��ʼ��ͼ��������
int LocateVetex(AdjMatrix * G, char v); 	//�󶥵�λ�ú���
int createUDG(AdjMatrix *G);							//��������ͼ UDG
int createUDN(AdjMatrix *G);							//���������� UDN
int createDG(AdjMatrix *G);							//��������ͼ DG
int createDN(AdjMatrix *G);							//���������� DN
void print(AdjMatrix *G);									//����ڽӾ���

//��ʼ��ͼ�������� 
void init(AdjMatrix *G, GraphKind kind){
	G->kind = kind;
} 

//�󶥵�λ�ú��� 
int LocateVetex(AdjMatrix * G, char v)	
{
	int j = Error, k;
	
	for(k = 0; k < G->vexnum; k++)
	{
		if(G->vertex[k] == v)
		{
			j = k;
//			printf("�����󶥵�λ�ú���, %d\n", j);
			break;
		}
	}
	return (j);
}

//============����ͼUDG======
//��������ͼ UDG
int createUDG(AdjMatrix *G){
	int i, j, k, weight = 1;
	char v1, v2;
	
	printf("����������ͼ�������ͻ�����");
	scanf("%d %d", &G->vexnum, &G->arcnum);
	getchar();
	
	for(i = 0; i < G->vexnum; i++){
		for(j = 0; j < G->vexnum; j++){
			G->arcs[i][j].adj = INFINITY;
		}
	}
	
	printf("��������ͼ�Ķ��㣺");
	for(i = 0; i < G->vexnum; i++){
		scanf("%c", &G->vertex[i]);
		getchar();
	}
	
	printf("����һ�������������㣺\n");
	for(k = 0; k < G->arcnum; k++){
		scanf("%c %c", &v1, &v2);
		getchar();
		i = LocateVetex(G, v1);
		j = LocateVetex(G, v2);
		G->arcs[i][j].adj = G->arcs[j][i].adj = weight;
	}
} 
//=========================== 

//============������UDN======
//���������� UDN
int createUDN(AdjMatrix *G){
	int i, j, k, weight;
	char v1, v2;
	
	printf("���������������Ķ������ͻ�����");
	scanf("%d %d", &G->vexnum, &G->arcnum);
	getchar();
	
	//��ʼ�� 
	for(i = 0; i < G->vexnum; i++)
	{
		for(j = 0; j < G->vexnum; j++)
		{
			G->arcs[i][j].adj = INFINITY;	//INFINITY
		}
	}
	
	//����ͼ�Ķ��� 
	printf("�������������Ķ��㣺");
	for(i = 0; i < G->vexnum; i++)
	{
		scanf("%c", &G->vertex[i]);
		getchar();
	}
	
	//����һ�������������㼰Ȩֵ 
	printf("������һ�������������㼰Ȩֵ(v1 v2 weight): \n"); 
	for(k = 0; k < G->arcnum; k++)
	{
		scanf("%c %c %d", &v1, &v2, &weight);
		getchar();
		i = LocateVetex(G, v1);
		j = LocateVetex(G, v2);
		G->arcs[i][j].adj = G->arcs[j][i].adj =weight;
	}
	return (OK);
} 
//=========================== 

//==========����ͼDG=========
//��������ͼ DG
int createDG(AdjMatrix * G)
{
	int i, j, k, weight = 1;
	char v1, v2;
	
	printf("����������ͼ���Ķ������ͻ�����");
	scanf("%d %d", &G->vexnum, &G->arcnum);
	getchar();
	
	//��ʼ�� 
	for(i = 0; i < G->vexnum; i++)
	{
		for(j = 0; j < G->vexnum; j++)
		{
			G->arcs[i][j].adj = 0;	//INFINITY
		}
	}
	
	//����ͼ�Ķ��� 
	printf("����������ͼͼ�Ķ��㣺");
	for(i = 0; i < G->vexnum; i++)
	{
		scanf("%c", &G->vertex[i]);
		getchar();
	}
	
	//����һ�������������㼰Ȩֵ 
	printf("������һ��������������(v1 v2��v1Ϊβ��v2Ϊͷ): \n"); 
	for(k = 0; k < G->arcnum; k++)
	{
		scanf("%c %c", &v1, &v2);
		getchar();
		i = LocateVetex(G, v1);
		j = LocateVetex(G, v2);
		G->arcs[i][j].adj = weight;
	}
	return (OK);
}
//=========================== 

//==========������DN=========
//���������� DN
int createDN(AdjMatrix * G)
{
	int i, j, k, weight;
	char v1, v2;
	
	printf("���������������Ķ������ͻ�����");
	scanf("%d %d", &G->vexnum, &G->arcnum);
	getchar();
	
	//��ʼ�� 
	for(i = 0; i < G->vexnum; i++)
	{
		for(j = 0; j < G->vexnum; j++)
		{
			G->arcs[i][j].adj = 0;	//INFINITY
		}
	}
	
	//����ͼ�Ķ��� 
	printf("�������������Ķ��㣺");
	for(i = 0; i < G->vexnum; i++)
	{
		scanf("%c", &G->vertex[i]);
		getchar();
	}
	
	//����һ�������������㼰Ȩֵ 
	printf("������һ�������������㼰Ȩֵ(v1 v2 weight����v1Ϊβ��v2Ϊͷ): \n"); 
	for(k = 0; k < G->arcnum; k++)
	{
		scanf("%c %c %d", &v1, &v2, &weight);
		getchar();
		i = LocateVetex(G, v1);
		j = LocateVetex(G, v2);
		G->arcs[i][j].adj = weight;
	}
	return (OK);
}
//=========================== 


//============================ 
 
//����ڽӾ��� 
void print(AdjMatrix *G){
	int i, j;
	printf("����ڽӾ���Ϊ��\n");
	for(i = 0; i < G->vexnum; i++){
		for(j = 0; j < G->vexnum; j++){
			printf("%7d", G->arcs[i][j].adj);
		}
		printf("\n");
	}
}

int main(void)
{
	AdjMatrix G;
	GraphKind kind;

	while(1) {
		printf("��ѡ����Ҫ������ͼ���������ࣺ\n0:����ͼ \n1:������ \n2:����ͼ \n3:������ \n");
		scanf("%d", &kind);
		getchar();
		
		init(&G, kind); 
		switch(kind){
			case 0:
				createUDG(&G);	//����ͼ
				print(&G); 
				break;
				
			case 1:
				createUDN(&G);	//������ 
				print(&G); 
				break;
				
			case 2:
				createDG(&G); 	//����ͼ
				print(&G); 
				break;
				
			case 3:
				createDN(&G);		//������
				print(&G); 
				break;
			default:
				printf("�������������룡"); 
				printf("\n") ;
		}
			
		printf("\n");
	} 
	
	return 0;
}
