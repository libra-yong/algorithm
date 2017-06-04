/*
4NÄ§·½Õó 
*/

#include<stdio.h>
#include<stdlib.h>

#define N 8

int main(void){
	int i, j;
	int square[N+1][N+1] = {0};
	
	for(j = 1; j <= N; j++){
		for(i = 1; i <= N; i++){
			if(j%4 == i%4 || (j%4 + i%4) == 1){
				square[i][j] = (N+1-i) * N -j + 1;
			}else{
				square[i][j] = (i-1) * N + j;
			}
		}
	}
	
	for(i = 1; i <= N; i++){
		for(j = 1; j<= N; j++){
			printf("%2d ", square[i][j]);
		}
		printf("\n");
	}
	
	return 0;
} 
