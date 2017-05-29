/*
约瑟夫环 
一堆猴子都有编号，编号是1，2，3 ...m ,这群猴子（n个）按照1-m的顺序围坐一圈，从第1开始数，每数到第m个，该猴子
就要离开此圈，这样依次下来，直到圈中只剩下最后一只猴子，则该猴子为大王。请设计算法编写程序输出为大王的猴子的
编号。
*/
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	
	int count = 1;
	int i = 0, pos = -1;
	
	//存活 
	int alive = 0;
	int n, m;
	int man[1000] = {0};
	printf("请输入猴子个数和死亡编号（例如：50 4）："); 
	scanf("%d %d", &n, &m);
	getchar();
	
	/*
	初始化死亡顺序，当数到m时退出do-while循环 ，依次设置正常编号所对应的死亡排列序号 
	*/
	while(count <= n){
		do{
			pos = (pos + 1) % n;
			if(man[pos] == 0){
				i++;
			}
			 
			if(i == m){
				i = 0;
				break;
			}
		}while(1);
		
		man[pos] = count;
		count++;
	}
	
	printf("猴子原排列顺序为：");
	for(i = 0; i < n; i++){
		printf("%3d ", i+1);
	} 
	
	printf("\n对应的死亡顺序为: ");
	for( i = 0; i < n; i++){
		printf("%3d ", man[i]);
	}
	
	printf("\n猴大王的位置编号（原排列编号）为: ");
	for(i = 0; i < n; i++){
		if(man[i] > n-1){
			
			//注意数学中的序号从1开始和程序语言中的序号从0开始
			printf("%3d ", i+1); 
			continue; 
		}
		
	} 
	printf("\n");
	
	return 0;
}
