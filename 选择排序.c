/*
选择排序
（题目要求数据为正不受限，此题无法进行大数排序，且缺少容错机制） 
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100
#define SWAP(x, y) {int t; t = x; x = y; y = t;}

void selsort(int [], int); 		 //选择排序

//选择排序
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
		printf("第 %d 次排序: ", i + 1);
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
	
	printf("请输入你要输入数字的个数："); 
	scanf("%d", &num); 
	getchar();
	printf("请输入正整数："); 
	for(i = 0; i < num; i++){
		scanf("%d", &number[i]);
		getchar();
	}
	
	printf("选择排序：\n");
	selsort(number, num);

	return 0;
}
