/*
ѡ������
����ĿҪ������Ϊ�������ޣ������޷����д���������ȱ���ݴ���ƣ� 
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100
#define SWAP(x, y) {int t; t = x; x = y; y = t;}

void selsort(int [], int); 		 //ѡ������

//ѡ������
void selsort(int number[], int num)
{
	int i, j, k, m;
	
	for(i = 0; i < num - 1; i++)
	{
		m = i; 
		for(j = i + 1; j < num; j++)
		{
			if(number[j] < number[m])
			{
				m = j;
			}
		}
		if(i != m)
		{
			SWAP(number[i], number[m]); 
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
	int number[MAX];
	int num, i;
	
	printf("��������Ҫ�������ֵĸ�����"); 
	scanf("%d", &num); 
	getchar();
	printf("��������������"); 
	for(i = 0; i < num; i++){
		scanf("%d", &number[i]);
		getchar();
	}
	
	printf("ѡ������\n");
	selsort(number, num);

	return 0;
}
