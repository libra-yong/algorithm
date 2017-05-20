/*
�ϲ�˳���
�ϲ����������� 
*/ 

#include<stdio.h>
#include<string.h> 


#define MAXSIZE 100
typedef struct{
	int data[MAXSIZE];	
	int len;	//���ݳ��� 
}List;

//��ʼ��˳��� 
List* initList(List *L){
	int num, i;
	int data;
	//����˳�����
	printf("������˳����ȣ�0<len<100): ");
	scanf("%d", &num);
	getchar();
	L->len = num;
	
	//�������� 
	for(i = 0; i < L->len; i++){
		printf("������� %d ������", i);
		scanf("%d", &data);
		getchar();
		L->data[i] = data;
	}
	return L;
}

//�ϲ�˳���Ϊ�ǵݼ������ 
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

//��ӡ 
List* print(List *L){
	int i;
	printf("===================˳�������===================\n");
	printf("���� %d ������: ", L->len); 
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
