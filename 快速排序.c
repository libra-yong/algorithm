/*
快速排序 （题目要求数据为正不受限，此题无法对大数运算，且缺少容错机制） 
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100
#define SWAP(x, y) {int t; t = x; x = y; y = t;}

void quicksort(int [], int left, int right);		//快速排序 

//快速排序 
void quicksort(int number[], int left, int right){
	int i, j, s;
	if(left < right){
		s = number[(left + right) / 2];
		i = left - 1;
		j = right + 1;
		while(1){
			while(number[++i] < s);	//向右找 
			while(number[--j] > s);	//向左找 
			if(i >= j){
				break;
			}
			SWAP(number[i], number[j]);
		}
		quicksort(number, left, i - 1);		//对左边进行递回 
		quicksort(number, j + 1, right);	//对右边进行递回 
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
	
	printf("快速排序:\n");
	quicksort(number, 0, num-1);
	for(i = 0; i < num; i++){
		printf("%d ", number[i]);
	}
	return 0;
} 
