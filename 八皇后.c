/*
八皇后问题
国际西洋棋棋手马克斯·贝瑟尔于1848年提出在8X8格的国际象棋上摆放八个皇后，使其不能互相攻击，即任意两个皇后都不
能处于同一行、同一列或同一斜线上，问有多少种摆法。请设计算法编写程序解决
*/

#include <stdio.h>
#include <stdlib.h>

#define N 8

int column[N+1];	// 同行是否有皇后，1表示有 
int rup[2*N+1];		// 右上至左下是否有皇后 
int lup[2*N+1];		// 左上至右下是否有皇后 
int queen[N+1] = {0};
int num;			//解答编号 

void backtrack(int);	//递回求解 
void showAnswer();		//打印答案 

int main(void)
{
	int i;
	num = 0;
	
	//初始化每个为皇后 
	for(i = 1; i <= N; i++)
	{
		column[i] = 1;
	}
	
	for(i = 1; i <= 2*N; i++)
	{
		rup[i] = lup[i] = 1;
	}
	
	backtrack(1);
	
	return 0;
}

//打印答案
void showAnswer()
{
	int x, y;
	printf("\n解答 %d \n", ++num);
	
	//行 
	for(y = 1; y <= N; y++)
	{
		//列 
		for(x = 1; x <= N; x++)
		{
			//输出每行的仅有的皇后 
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

//递回求解，依次算出1-8行的皇后位置
void backtrack(int i)
{
	int j; 
	
	//输出8行
	if(i > N)
	{
		showAnswer();
	}
	else
	{
		//每行的没个数
		for(j = 1; j <= N; j++)
		{
			if(column[j] == 1 && rup[i+j] == 1 && lup[i-j+N] == 1)
			{
				//记录第i行的皇后位置j
				queen[i] = j;
				
				//以第i行的第j个数为中心，其所在的米字格清空皇后
				column[j] = rup[i+j] = lup[i-j+N] = 0;
				
				//递回 
				backtrack(i+1);
				
				column[j] = rup[i+j] = lup[i-j+N] = 1;
			}
		}
	}
}

