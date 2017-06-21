/*
数塔，从顶部出发，在每一结点可以选择向左走或是向右走，一直走到底层，要求找出一条路径，使路径上的数值和最大
data[]: 数塔每一层的数据
d[]: 数塔每一阶段路径上的数值和 
*/ 

#include<iostream>
using namespace std;

int data[100][100] = {0};

void MAX(int d[100][100], int max) {
	
	for (int i = 4; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			//记录每层路径最大值 
			d[i][j] = (d[i+1][j] > d[i+1][j+1]) ? d[i+1][j] + data[i][j] : d[i+1][j+1] + data[i][j];
			//求路径最大值 
			max = (max > d[i][j]) ? max : d[i][j];
		}
	}
	cout << "输出为: " << endl; 
	for (int i = 0; i <= 4; i++) {
		for (int j = 0; j <= i; j++) {
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "路径最大值为: " << max << endl;
	
	int b = 0;
	cout << "路径为: "; 
	cout << data[0][0] << " ";
	int x = 0;  	//x控制输出的路径, 若去掉x则会在后面输出许多0 
	for (int i = 0; i <= 4;) {
		for (int j = 0; j <= i;) {
			b = d[i][j] - data[i][j];
			if (b == d[i+1][j] && x < 4) {
				cout << data[i+1][j] << " ";
				i += 1;
				x++;
			} else if (b == d[i+1][j+1] && x < 4){
				cout << data[i+1][j+1] << " ";
				i += 1;
				j += 1;
				x++;
			}
		}
	}
}

int main(void) {
	int d[100][100] = {0};
	int max = 0;
	data[0][0] = 9;
	data[1][0] = 12, data[1][1] = 15;
	data[2][0] = 10, data[2][1] = 6, data[2][2] = 8;
	data[3][0] = 2, data[3][1] = 18, data[3][2] = 9, data[3][3] = 5;
	data[4][0] = 19, data[4][1] = 7, data[4][2] = 10, data[4][3] = 4, data[4][4] = 16;
	
	MAX(d, max);
	return 0;
} 
