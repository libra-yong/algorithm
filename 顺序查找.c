/*
�۰����
���ݴ���� 
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define SWAP(x,y) {int t; t = x; x = y; y = t;}

void quicksort(int[], int, int);	//��������
int search(int[], int, int);			//˳�����

//˳�����
int search(int number[], int num, int find){
	int i;
	
	for(i = 0; i < num; i++){
		if(number[i] == find){
			return i;
		}
	}
	return -1;
} 

//�������� 
void quicksort(int number[], int left, int right) {
	int i, j, k, s;
	if(left < right) {
		s = number[(left+right)/2];
		i = left - 1;
		j = right + 1;
		while(1) {
			while(number[++i] < s) ; // ������
			while(number[--j] > s) ; // ������
			if(i >= j)
			break; 
			SWAP(number[i], number[j]);
		}
		  
		quicksort(number, left, i-1);// ����߽��еݻ�
		  
		
		quicksort(number, j+1, right); // ���ұ߽��еݻ�
	}
}

//������ 
int main(void) {
	int number[MAX];
	int i, num, find;
	
	printf("��������Ҫ����ĸ�����");
	scanf("%d", &num);
	getchar();
	
	printf("��������Ҫ���������: "); 
	for(i = 0; i < num; i++) {
		scanf("%d", &number[i]);
		getchar();
	}
	
	quicksort(number, 0, num-1);
	
	printf("���У�");
	for(i = 0; i < num; i++)
		printf("%d ", number[i]);
		
	printf("\n����Ѱ�Ҷ���");
	scanf("%d", &find);
	if((i = search(number, num, find)) >= 0) 
		printf("�ҵ����������� %d ", i+1);
	else
		printf("\n�Ҳ���ָ����");
	printf("\n");
	
	return 0;
}



