#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int num[100];
	int n, i, j, k, x, low, high, mid;
	
	printf("�������������Ŀ��");
	scanf("%d", &n);
	getchar();
	
	printf("���� %d ������", n);
	for ( i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
		getchar();
	}
	
	printf("�۰��������\n");
	for (i = 2; i <= n; i++) {
		x = num[i];
		low = 1; 
		high = i - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (x < num[mid]) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		
		for (j = i - 1; j >= low; j--) {
			num[j+1] = num[j]; 
		}
		num[low] = x;
		
		printf("�� %d �����ţ�", i-1);
		for ( k = 1; k <= n; k++) {
			printf("%d ", num[k]);
		}
		printf("\n");
	}
	return 0;
}
