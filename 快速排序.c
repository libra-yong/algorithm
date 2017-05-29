/*
�������� ����ĿҪ������Ϊ�������ޣ������޷��Դ������㣬��ȱ���ݴ���ƣ� 
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100
#define SWAP(x, y) {int t; t = x; x = y; y = t;}

void quicksort(int [], int left, int right);		//�������� 

//�������� 
void quicksort(int number[], int left, int right){
	int i, j, s;
	if(left < right){
		s = number[(left + right) / 2];
		i = left - 1;
		j = right + 1;
		while(1){
			while(number[++i] < s);	//������ 
			while(number[--j] > s);	//������ 
			if(i >= j){
				break;
			}
			SWAP(number[i], number[j]);
		}
		quicksort(number, left, i - 1);		//����߽��еݻ� 
		quicksort(number, j + 1, right);	//���ұ߽��еݻ� 
	}
}

int main(void){
	int number[MAX], num, i;
	
	printf("��������Ҫ�������ֵĸ�����"); 
	scanf("%d", &num); 
	getchar();
	printf("��������������"); 
	for(i = 0; i < num; i++){
		scanf("%d", &number[i]);
		getchar();
	}
	
	printf("��������:\n");
	quicksort(number, 0, num-1);
	for(i = 0; i < num; i++){
		printf("%d ", number[i]);
	}
	return 0;
} 
