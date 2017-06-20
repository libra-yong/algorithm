package dynamic;

import java.util.*;
/**
* @author: libra
* @address: github: https://github.com/libra-yong
* create on 2017-06-20
*/

/**
 * 已知序列Z是序列X和序列Y的最长公共子序列
 * x(m) = y(n), 则z(k)=x(m) = y(n), 且z(k-1)是X(m-1)和Y(n-1)的最长公共子序列
 * x(m) != y(n), 且z(k) != x(m), 则Z是X(m-1)和Y的最长公共子序列
 * x(m) != y(n), 且z(k) != y(n), 则Z是X(m)和Y(n-1)的最长公共子序列
 * c[i][j] 表示X(i)和Y(j)的最长公共子序列的长度
 * i=j=0, c[i][j] = 0
 * i,j>0, x(i) = y(j), c[i][j] = c[i-1][j-1]+1
 * i,j>0, x(i) != y(j), max(c[i][j-1], c[i-1][j]) + 1
 * */
public class LcsLength {
	public static int lcsLength(char[] x, char[] y, int[][] b) {
		int m = x.length - 1;
		int n = y.length - 1;
		int[][] c = new int[m+1][n+1];
		//序列y长度为0
		for (int i = 1; i <= m; i++) {
			c[i][0] = 0;
		}
		//序列x长度为0
		for (int i = 1; i <= n; i++) {
			c[0][i] = 0;
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (x[i] == y[j]) {
					c[i][j] = c[i-1][j-1] + 1;
					b[i][j] = 1;
				} else if (c[i-1][j] > c[i][j-1]) {
					c[i][j] = c[i-1][j];
					b[i][j] = 2;
				} else if (c[i-1][j] <= c[i][j-1]) {
					c[i][j] = c[i][j-1];
					b[i][j] = 3;
				}
			}
		}
		System.out.println("最长公共子序列的长度为: " + c[m][n]);
		
		System.out.print("最长公共子序列为: ");
		lcs(m, n, x, b);	//输出最长子序列
		return c[m][n];
	}

	/**
	 * b[i][j] = 1 : x(i)和y(j)的最长公共子序列为x(i-1)和y(j-1)的最长公共子序列加上x[i]
	 * b[i][j] = 2 : x(i)和y(j)的最长公共子序列为x(i-1)和y(j)的最长公共子序列
	 * b[i][j] = 3 : x(i)和y(j)的最长公共子序列为x(i)和y(j-1)的最长公共子序列
	 * */
	public static void lcs(int i, int j, char[] x, int[][] b) {
		if (i ==0 || j == 0) {
			return ;
		}
		if (b[i][j] == 1) {
			lcs(i-1, j-1, x, b);
			System.out.print(x[i]);
		} else if (b[i][j] == 2) {
			lcs(i-1, j, x, b);
		} else if (b[i][j] == 3) {
			lcs(i, j - 1, x, b);
		}
	}
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		/*
		 * 测试:
		 * 注意: 字符序列从第1个位置开始, 第0个位置设为空
		char[] x = new char[]{' ', 'a','b','c','d','k','k','k'};
		char[] y = new char[]{' ', 'b','a','a','b','c','d','a','d','a','b','c'};*/
		int[][] b = new int[20][20];
		
		//第一个字符序列
		System.out.print("请输入第一个字符串:");
		String str = input.nextLine();
		str = " ".concat(str);			//字符串前面加一个空格符
		char[] x = str.toCharArray();	//字符串转化为字符数组
		
		//第二个字符序列
		System.out.print("请输入第二个字符串:");
		str = input.next();
		str = " ".concat(str);
		char[] y = str.toCharArray();
		
		lcsLength(x, y, b);	//4, abcd
	}

}
