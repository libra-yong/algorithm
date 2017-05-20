/*
合并顺序表
合并部分有问题 
*/ 

#include<stdio.h>
#include<string.h> 


#define MAXSIZE 100
typedef struct{
	int data[MAXSIZE];	
	int len;	//数据长度 
}List;

//初始化顺序表 
List* initList(List *L){
	int num, i;
	int data;
	//输入顺序表长度
	printf("请输入顺序表长度（0<len<100): ");
	scanf("%d", &num);
	getchar();
	L->len = num;
	
	//输入数据 
	for(i = 0; i < L->len; i++){
		printf("请输入第 %d 个数：", i);
		scanf("%d", &data);
		getchar();
		L->data[i] = data;
	}
	return L;
}

//合并顺序表为非递减有序表 
List* mergeList(List *La, List *Lb){
	List *L;
	int i, j, k;
	i = j = k = 0;
	
	while(i <= La->len - 1 && j <= Lb->len - 1){
		 
		if(La->data[i] <= Lb->data[j]){
			L->data[k] = La->data[i];
			
			k++;
			i++;
		}else{
			L->data[k] = Lb->data[j];
			k++;
			j++; 
		}
	}
	
	while(i <= La->len - 1){
		L->data[k] = La->data[i];
		k++;
		i++;
	}
	while(j <= Lb->len - 1){
		L->data[k] = La->data[j];
		k++;
		j++;
	}
	L->len = La->len + Lb->len; 
	return L;
} 

//打印 
List* print(List *L){
	int i;
	printf("===================顺序表如下===================\n");
	printf("共有 %d 个数据: ", L->len); 
	for(i = 0; i < L->len; i++){
		printf("%d ", L->data[i]);
	}
	printf("\n\n");
	return L;
}

int main(void){
	List La, Lb;
	initList(&La);
	print(&La);
	initList(&Lb);
	print(&Lb);
	mergeList(&La, &Lb);
	return 0;
} 
