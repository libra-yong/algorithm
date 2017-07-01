/*
shell���򷨣������Ĳ������� 
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10
#define SWAP(x, y) {int t; t =x; x = y; y =t;}

void shellsort(int []);

int main(void){
	int number[MAX] = {0};
	int i;
	
	srand(time(NULL));
	printf("����ǰ�� ");
	for(i = 0; i < MAX; i++){
		number[i] = rand()%100;
		printf("%d ", number[i]);
	}
	
	shellsort(number);
	
	return 0;
}

void shellsort(int number[]){
	int i, j, k, gap, t;
	
	gap = MAX / 2;
	
	while(gap > 0){
		for(k = 0; k < gap; k++){
			for(i = k + gap; i < MAX; i++){
				for(j = i - gap; j >= k; j-=gap){
					if(number[j] > number[j + gap]){
						SWAP(number[j], number[j+gap]);
					}else{
						break;
					}
				}
			}
		}
		printf("\ngap = %d : ", gap);
		for(i = 0; i < MAX; i++){
			printf("%d ", number[i]);
		}
		printf("\n");
		gap /= 2;
	}
}
