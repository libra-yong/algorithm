/*
冒泡排序 （题目要求数据为正不受限，此题无法对大数运算，且缺少容错机制） 
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100
#define SWAP(x, y) {int t; t = x; x = y; y = t;}

void bubsort(int [], int); 			//冒泡排序

//冒泡排序
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
		
		printf("第 %d 次排序: ", i + 1);
		for(k = 0; k < num; k++)
		{
			printf("%d ", number[k]);
		}
		printf("\n");
	}
}

int main(void){
	int number[MAX], num, i;
	
	printf("请输入你要输入数字的个数："); 
	scanf("%d", &num); 
	getchar();
	printf("请输入正整数："); 
	for(i = 0; i < num; i++){
		scanf("%d", &number[i]);
		getchar();
	}
	printf("冒泡排序:\n");
	bubsort(number, num);
	
	return 0;
} 
