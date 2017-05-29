/*
折半查找
无容错机制 
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define SWAP(x,y) {int t; t = x; x = y; y = t;}

void quicksort(int[], int, int);	//快速排序
int search(int[], int, int);			//顺序查找

//顺序查找
int search(int number[], int num, int find){
	int i;
	
	for(i = 0; i < num; i++){
		if(number[i] == find){
			return i;
		}
	}
	return -1;
} 

//快速排序 
void quicksort(int number[], int left, int right) {
	int i, j, k, s;
	if(left < right) {
		s = number[(left+right)/2];
		i = left - 1;
		j = right + 1;
		while(1) {
			while(number[++i] < s) ; // 向右找
			while(number[--j] > s) ; // 向左找
			if(i >= j)
			break; 
			SWAP(number[i], number[j]);
		}
		  
		quicksort(number, left, i-1);// 对左边进行递回
		  
		
		quicksort(number, j+1, right); // 对右边进行递回
	}
}

//主函数 
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
	
	quicksort(number, 0, num-1);
	
	printf("数列：");
	for(i = 0; i < num; i++)
		printf("%d ", number[i]);
		
	printf("\n输入寻找对象：");
	scanf("%d", &find);
	if((i = search(number, num, find)) >= 0) 
		printf("找到数字于索引 %d ", i+1);
	else
		printf("\n找不到指定数");
	printf("\n");
	
	return 0;
}



