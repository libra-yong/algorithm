/*
图的存储结构
邻接矩阵表示法 

在建立无权图时无法输出字符的无穷大，四种图或网分别有一个创建（考虑将四种创建合并？），没有容错机制 
*/

#include <stdio.h> 
#include<stdlib.h>

#define 	MAX_VERTEX_NUM 		20			//最多顶点个数 
#define 	INFINITY 			32678		//表示极大值，即无穷 
#define OK 1
#define Error -1
#define MAX 100

typedef enum{DG, DN, UDG, UDN} GraphKind;	//图的种类：有向图，有向网，无向图，无向网 

//定义边权值 
typedef struct ArcNode
{
	int adj;		//对于无权图，用1或0表示是否相邻；对带权图，则为权值类型
	int info;
}ArcNode;

//定义图或网 
typedef struct 
{
	char vertex[MAX_VERTEX_NUM];		//顶点向量 
	ArcNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];	//邻接矩阵 
	int vexnum, arcnum;		//图的顶点数和弧数 
	GraphKind kind;			//图的种类标志 
}AdjMatrix;

void init(AdjMatrix *G, GraphKind kind);	//初始化图或网种类
int LocateVetex(AdjMatrix * G, char v); 	//求顶点位置函数
int createUDG(AdjMatrix *G);							//建立无向图 UDG
int createUDN(AdjMatrix *G);							//建立无向网 UDN
int createDG(AdjMatrix *G);							//建立有向图 DG
int createDN(AdjMatrix *G);							//建立有向网 DN
void print(AdjMatrix *G);									//输出邻接矩阵

//初始化图或网种类 
void init(AdjMatrix *G, GraphKind kind){
	G->kind = kind;
} 

//求顶点位置函数 
int LocateVetex(AdjMatrix * G, char v)	
{
	int j = Error, k;
	
	for(k = 0; k < G->vexnum; k++)
	{
		if(G->vertex[k] == v)
		{
			j = k;
//			printf("进入求顶点位置函数, %d\n", j);
			break;
		}
	}
	return (j);
}

//============无向图UDG======
//建立无向图 UDG
int createUDG(AdjMatrix *G){
	int i, j, k, weight = 1;
	char v1, v2;
	
	printf("请输入无向图顶点数和弧数：");
	scanf("%d %d", &G->vexnum, &G->arcnum);
	getchar();
	
	for(i = 0; i < G->vexnum; i++){
		for(j = 0; j < G->vexnum; j++){
			G->arcs[i][j].adj = INFINITY;
		}
	}
	
	printf("输入无向图的顶点：");
	for(i = 0; i < G->vexnum; i++){
		scanf("%c", &G->vertex[i]);
		getchar();
	}
	
	printf("输入一条弧的两个顶点：\n");
	for(k = 0; k < G->arcnum; k++){
		scanf("%c %c", &v1, &v2);
		getchar();
		i = LocateVetex(G, v1);
		j = LocateVetex(G, v2);
		G->arcs[i][j].adj = G->arcs[j][i].adj = weight;
	}
} 
//=========================== 

//============无向网UDN======
//建立无向网 UDN
int createUDN(AdjMatrix *G){
	int i, j, k, weight;
	char v1, v2;
	
	printf("请输入无向网弧的顶点数和弧数：");
	scanf("%d %d", &G->vexnum, &G->arcnum);
	getchar();
	
	//初始化 
	for(i = 0; i < G->vexnum; i++)
	{
		for(j = 0; j < G->vexnum; j++)
		{
			G->arcs[i][j].adj = INFINITY;	//INFINITY
		}
	}
	
	//输入图的顶点 
	printf("请输入无向网的顶点：");
	for(i = 0; i < G->vexnum; i++)
	{
		scanf("%c", &G->vertex[i]);
		getchar();
	}
	
	//输入一条弧的两个顶点及权值 
	printf("请输入一条弧的两个顶点及权值(v1 v2 weight): \n"); 
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

//==========有向图DG=========
//建立有向图 DG
int createDG(AdjMatrix * G)
{
	int i, j, k, weight = 1;
	char v1, v2;
	
	printf("请输入有向图弧的顶点数和弧数：");
	scanf("%d %d", &G->vexnum, &G->arcnum);
	getchar();
	
	//初始化 
	for(i = 0; i < G->vexnum; i++)
	{
		for(j = 0; j < G->vexnum; j++)
		{
			G->arcs[i][j].adj = 0;	//INFINITY
		}
	}
	
	//输入图的顶点 
	printf("请输入有向图图的顶点：");
	for(i = 0; i < G->vexnum; i++)
	{
		scanf("%c", &G->vertex[i]);
		getchar();
	}
	
	//输入一条弧的两个顶点及权值 
	printf("请输入一条弧的两个顶点(v1 v2，v1为尾，v2为头): \n"); 
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

//==========有向网DN=========
//建立有向网 DN
int createDN(AdjMatrix * G)
{
	int i, j, k, weight;
	char v1, v2;
	
	printf("请输入有向网弧的顶点数和弧数：");
	scanf("%d %d", &G->vexnum, &G->arcnum);
	getchar();
	
	//初始化 
	for(i = 0; i < G->vexnum; i++)
	{
		for(j = 0; j < G->vexnum; j++)
		{
			G->arcs[i][j].adj = 0;	//INFINITY
		}
	}
	
	//输入图的顶点 
	printf("请输入有向网的顶点：");
	for(i = 0; i < G->vexnum; i++)
	{
		scanf("%c", &G->vertex[i]);
		getchar();
	}
	
	//输入一条弧的两个顶点及权值 
	printf("请输入一条弧的两个顶点及权值(v1 v2 weight，，v1为尾，v2为头): \n"); 
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
 
//输出邻接矩阵 
void print(AdjMatrix *G){
	int i, j;
	printf("输出邻接矩阵为：\n");
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
		printf("请选择你要建立的图或网的种类：\n0:无向图 \n1:无向网 \n2:有向图 \n3:有向网 \n");
		scanf("%d", &kind);
		getchar();
		
		init(&G, kind); 
		switch(kind){
			case 0:
				createUDG(&G);	//无向图
				print(&G); 
				break;
				
			case 1:
				createUDN(&G);	//无向网 
				print(&G); 
				break;
				
			case 2:
				createDG(&G); 	//有向图
				print(&G); 
				break;
				
			case 3:
				createDN(&G);		//有向网
				print(&G); 
				break;
			default:
				printf("错误！请重新输入！"); 
				printf("\n") ;
		}
			
		printf("\n");
	} 
	
	return 0;
}
