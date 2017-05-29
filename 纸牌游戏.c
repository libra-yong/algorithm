/*
纸牌游戏 
*/


#include<stdio.h>
#include<stdlib.h>

//用结构体有点多余 
typedef struct Card{
	int flag;//0表示正面，1表示反面 
}Card;

int main(void){
	Card card[52] = {0};
	int i, j;
	
	//从2开始依次翻牌 
	for(i = 1; i < 52; i++){
		for(j = i; j < 52; j++){
			//若基数能被其倍数整除则翻转牌面 
			if(((j+1) % (i+1)) == 0){
				//原来为正面则现在为反面，原来为反面则现在为正面 
				if(card[j].flag == 0){
					card[j].flag = 1;
				}else if(card[j].flag == 1){
					card[j].flag = 0;
				}
			}
		}
	}
	
	//输出正面的牌（即flag为0） 
	printf("正面向上的牌为："); 
	for(i = 0; i < 52; i++){
		if(card[i].flag == 0){
			//i+1为牌的编号，因为数组从0开始存储 
			printf("%d ", i+1);
		}
	}
	
	return 0;
}
