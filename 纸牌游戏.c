/*
ֽ����Ϸ 
*/


#include<stdio.h>
#include<stdlib.h>

//�ýṹ���е���� 
typedef struct Card{
	int flag;//0��ʾ���棬1��ʾ���� 
}Card;

int main(void){
	Card card[52] = {0};
	int i, j;
	
	//��2��ʼ���η��� 
	for(i = 1; i < 52; i++){
		for(j = i; j < 52; j++){
			//�������ܱ��䱶��������ת���� 
			if(((j+1) % (i+1)) == 0){
				//ԭ��Ϊ����������Ϊ���棬ԭ��Ϊ����������Ϊ���� 
				if(card[j].flag == 0){
					card[j].flag = 1;
				}else if(card[j].flag == 1){
					card[j].flag = 0;
				}
			}
		}
	}
	
	//���������ƣ���flagΪ0�� 
	printf("�������ϵ���Ϊ��"); 
	for(i = 0; i < 52; i++){
		if(card[i].flag == 0){
			//i+1Ϊ�Ƶı�ţ���Ϊ�����0��ʼ�洢 
			printf("%d ", i+1);
		}
	}
	
	return 0;
}
