/*
2(2N+1)Ä§·½Õó 
*/

#include<stdio.h>
#include<stdlib.h>

#define N 6
#define SWAP(x, y) {int t; t = x; x = y; y = t;}

void magic_o(int [][N], int);
void exchange(int [][N], int);

int main(void){
	int square[N][N] = {0};
	int i, j;
	magic_o(square, N/2);
	exchange(square, N);
	
	for(i = 0; i < N; i++){
		for( j = 0; j < N; j++){
			printf("%2d ", square[i][j]);
		}
		putchar('\n');
	}
	return 0;
}

void magic_o(int square[][N], int n){
	int count, row, column;
	row = 0;
	column = n /2;
	
	for(count = 1; count <= n*n; count++){
		square[row][column] = count;
		square[row+n][column+n] = count + n*n;
		square[row][column+n] = count + 2*n*n;
		square[row+n][column] = count + 3*n*n;
		if(count % n == 0){
			row++;
		}else{
			row = (row == 0) ? n - 1 : row - 1;
			column = (column == n - 1) ? 0 : column + 1;
		}
	}
}

void exchange(int x[][N], int n){
	int i, j;
	int m = n / 4;
	int m1 = m - 1;
	
	for(i = 0; i < n/2; i++){
		if(i != m){
			for(j = 0; j < m; j++){
				SWAP(x[i][j], x[n/2+i][j]);
			}
			for(j = 0; j < m1; j++){
				SWAP(x[i][n-1-j], x[n/2+i][n-1-j]);
			}
		}else{
			for(j = 1; j <= m; j++){
				SWAP(x[m][j], x[n/2+m][j]); 
			}
			for(j = 0; j <= m1; j++){
				SWAP(x[m][n-1-j], x[n/2+m][n-1-j]); 
			}
		}
	}
}

