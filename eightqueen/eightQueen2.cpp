/*
�ǵݹ��˻ʺ� 
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 8

int column[N+1];	// ͬ���Ƿ��лʺ�1��ʾ�� 
int queen[N+1] = {0};
int num;			//����� 

void backtrack();	//�ݻ���� 

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

//������ 
void showAnswer()
{
	int x, y;
	printf("\n�ⷨ %d: \n", ++num);
	
	for(y = 1; y <= N; y++)
	{
		for(x = 1; x <= N; x++)
		{
			if(queen[y] == x)
			{
				printf("��");
			}
			else
			{
				printf("��"); 
			} 
		}
		printf("\n");
	}
}

//�ж��Ƿ�������,��,б�ߵ�Լ������.
bool place(int k) {
	for (int j = 1; j < k; j++) {
		if ((abs(k-j) == abs(queen[j]-queen[k])) || (queen[j] == queen[k])) {
			return false;	//��ͬһ�����򲻷�������,����false 
		}
	}
	return true;
}

void backtrack()
{
	queen[1] = 0;
	int k = 1;
	while(k > 0) {
		queen[k] += 1;	//��һ����queen[k]�Ľ�,N����� 
		while((queen[k] <= N) && !(place(k))) {
			queen[k] += 1;	//��һ����� 
		}
		if (queen[k] <= N) {
			if (k == N) {
				showAnswer();	//��ӡ��� 
			} else {
				k++;					//��һ���ʺ� 
				queen[k] = 0;	//��ͷ��ʼ 
			}
		} else {
			k--;
		}
	}
}
