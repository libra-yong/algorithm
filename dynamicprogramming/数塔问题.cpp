/*
�������Ӷ�����������ÿһ������ѡ�������߻��������ߣ�һֱ�ߵ��ײ㣬Ҫ���ҳ�һ��·����ʹ·���ϵ���ֵ�����
data[]: ����ÿһ�������
d[]: ����ÿһ�׶�·���ϵ���ֵ�� 
*/ 

#include<iostream>
using namespace std;

int data[100][100] = {0};

void MAX(int d[100][100], int max) {
	
	for (int i = 4; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			//��¼ÿ��·�����ֵ 
			d[i][j] = (d[i+1][j] > d[i+1][j+1]) ? d[i+1][j] + data[i][j] : d[i+1][j+1] + data[i][j];
			//��·�����ֵ 
			max = (max > d[i][j]) ? max : d[i][j];
		}
	}
	cout << "���Ϊ: " << endl; 
	for (int i = 0; i <= 4; i++) {
		for (int j = 0; j <= i; j++) {
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "·�����ֵΪ: " << max << endl;
	
	int b = 0;
	cout << "·��Ϊ: "; 
	cout << data[0][0] << " ";
	int x = 0;  	//x���������·��, ��ȥ��x����ں���������0 
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
