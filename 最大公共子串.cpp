#include<iostream>
using namespace std; 

#define N 100
int fun(string s1, string s2)
{
	int a[N][N] = {0};
	int len1 = s1.length();	
	int len2 = s2.length();	
	int i,j;
	
	int max = 0;
	for(i = 1; i <= len1; i++){
		for(j = 1; j <= len2; j++){
			if(s1[i - 1] == s2[j - 1]) {
				a[i][j] = a[i - 1][j - 1] + 1; 
				if(a[i][j] > max) {
					max = a[i][j];
				} 
			}
		}
	}
	return max;
}

int main()
{
	string a, b;
	while (1) {
		cout << "请输入两个字符串："; 
		cin >> a >> b;
		cout << "最大公共字串长度为：" << fun(a, b) << endl << endl;
	}
	return 0;
}



