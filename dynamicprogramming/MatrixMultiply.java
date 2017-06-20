package dynamic;
/**
* @author: libra
* @address: github: https://github.com/libra-yong
* create on 2017-06-20
*/
/*
ra:数组a的行数
ca:数组a的列数
rb:数组b的行数
cb:数组b的列数
*/
public class MatrixMultiply {
	public static void matrixMultiply(int[][] a, int[][] b, int[][] c, int ra, int ca, int rb, int cb) {
		if (ca != rb) {
			throw new IllegalArgumentException("矩阵不可乘");
		}
		for (int i = 0; i < ra; i++) {
			for (int j = 0; j < cb; j++) {
				int sum = a[i][0] * b[0][j];
				for (int k = 1; k < ca; k++) {
					sum += a[i][k] * b[k][j];
				}
				c[i][j] = sum;
				System.out.print(c[i][j] + " ");
			}
			System.out.println();
		}
	}

	public static void main(String[] args) {
		int[][] a = new int[][] {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
		int[][] b = new int[][] {{100, 99, 98}, {97, 96, 95}, {94, 93, 92}, {91, 90, 89}};
		int[][] c = new int[a.length][a.length];
		matrixMultiply(a, b, c, a.length, a[0].length, b.length, b[0].length);
	}

}
