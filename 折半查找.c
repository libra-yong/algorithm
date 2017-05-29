/*
折半查找
无容错机制 
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define SWAP(x,y) {int t; t = x; x = y; y = t;}

void quicksort(int[], int, int);	//快速排序
int bisearch(int[], int, int);		//折半查找 

//折半查找 
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
	
	printf("请输入你要输入的个数：");
	scanf("%d", &num);
	getchar();
	
	printf("请输入你要输入的数字: "); 
	for(i = 0; i < num; i++) {
		scanf("%d", &number[i]);
		getchar();
	}
	
		
	printf("\n输入寻找对象：");
	scanf("%d", &find);
	if((i = bisearch(number, num, find)) >= 0) 
		printf("找到数字于索引 %d ", i+1);
	else
		printf("\n找不到指定数");
	printf("\n");
	
	return 0;
}


