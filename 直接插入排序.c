/*
直接插入排序 
*/
#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int num[100];
	int n, i, j, k;
	
	printf("请输入排序的数目：");
	scanf("%d", &n);
	getchar();
	
	printf("输入 %d 个数：", n);
	for ( i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
		getchar();
	}

	printf("直接插入排序:\n");
	for (i = 2; i <= n; i++) {
		num[0] = num[i];
		j = i - 1;
		while (num[0] < num[j]) {
			num[j+1] = num[j];
			j = j - 1;
		} 
		num[j+1] = num[0];
		printf("第 %d 次直排：", i-1);
		for ( k = 1; k <= n; k++) {
			printf("%d ", num[k]);
		}
		printf("\n");
	}
	return 0;
}
