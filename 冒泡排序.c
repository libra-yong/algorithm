/*
ð������ ����ĿҪ������Ϊ�������ޣ������޷��Դ������㣬��ȱ���ݴ���ƣ� 
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100
#define SWAP(x, y) {int t; t = x; x = y; y = t;}

void bubsort(int [], int); 			//ð������

//ð������
void bubsort(int number[], int num)
{
	int i, j, k, flag = 1;
	
	for(i = 0; i < num - 1 & flag == 1; i++)
	{
		flag = 0; 
		for(j = 0; j < num - i - 1; j++)
		{ 
			if(number[j + 1] < number[j])
			{
				SWAP(number[j + 1], number[j]);
				flag = 1; 
			}
		}
		
		printf("�� %d ������: ", i + 1);
		for(k = 0; k < num; k++)
		{
			printf("%d ", number[k]);
		}
		printf("\n");
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
	printf("ð������:\n");
	bubsort(number, num);
	
	return 0;
} 
