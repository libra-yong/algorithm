/*
非递归解八皇后 
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 8

int column[N+1];	// 同栏是否有皇后，1表示有 
int queen[N+1] = {0};
int num;			//解答编号 

void backtrack();	//递回求解 

int main(void)
{
	int i;
	num = 0;
	
	for(i = 1; i <= N; i++)
	{
		column[i] = 1;
	}
	
	backtrack();
	
	return 0;
}

//输出结果 
void showAnswer()
{
	int x, y;
	printf("\n解法 %d: \n", ++num);
	
	for(y = 1; y <= N; y++)
	{
		for(x = 1; x <= N; x++)
		{
			if(queen[y] == x)
			{
				printf("●");
			}
			else
			{
				printf("◎"); 
			} 
		}
		printf("\n");
	}
}

//判断是否满足行,列,斜线的约束条件.
bool place(int k) {
	for (int j = 1; j < k; j++) {
		if ((abs(k-j) == abs(queen[j]-queen[k])) || (queen[j] == queen[k])) {
			return false;	//在同一线上则不符合题意,返回false 
		}
	}
	return true;
}

void backtrack()
{
	queen[1] = 0;
	int k = 1;
	while(k > 0) {
		queen[k] += 1;	//逐一试验queen[k]的解,N种情况 
		while((queen[k] <= N) && !(place(k))) {
			queen[k] += 1;	//下一种情况 
		}
		if (queen[k] <= N) {
			if (k == N) {
				showAnswer();	//打印结果 
			} else {
				k++;					//下一个皇后 
				queen[k] = 0;	//从头开始 
			}
		} else {
			k--;
		}
	}
}
