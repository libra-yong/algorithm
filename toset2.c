/*
有字典顺序集合 
*/

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20

int main(void)
{
	int set[MAXSIZE];
	int i, n, position = 0;
	
	printf("输入集合个数：");
	scanf("%d", &n);
	printf("\n{}");
	set[position] = 1;
	
	while(1)
	{
		printf("\n{%d", set[0]);
		for(i = 1; i <= position; i++)
		{
			printf("%d", set[i]);
		}
		printf("}");
		if(set[position] < n)
		{
			set[position + 1] = set[position] + 1;
			position++;
		}
		else if(position != 0)
		{
			position--;
			set[position]++;
		}
		else
		{
			break;
		}
	}
	printf("\n");
	
	return 0;
}
