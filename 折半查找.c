/*
�۰����
���ݴ���� 
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define SWAP(x,y) {int t; t = x; x = y; y = t;}

void quicksort(int[], int, int);	//��������
int bisearch(int[], int, int);		//�۰���� 

//�۰���� 
int bisearch(int number[], int num, int find) {
	int low, mid, upper;
	low = 0;
	upper = num - 1;
	while(low <= upper) {
		mid = (low+upper) / 2;
		if(number[mid] < find)
			low = mid+1;
		else if(number[mid] > find)
			upper = mid - 1;
		else
			return mid;
	}
	return -1;
}


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
	
		
	printf("\n����Ѱ�Ҷ���");
	scanf("%d", &find);
	if((i = bisearch(number, num, find)) >= 0) 
		printf("�ҵ����������� %d ", i+1);
	else
		printf("\n�Ҳ���ָ����");
	printf("\n");
	
	return 0;
}


