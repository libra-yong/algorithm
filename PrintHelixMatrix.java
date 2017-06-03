/**
* @author: libra天秤
* create on 2017年6月3日 下午10:23:00
* github: https://github.com/libra-yong/demo
*/
/**输出螺旋阵*/
import java.util.Scanner;

public class PrintHelixMatrix {
	public static int N;
	
	public static void fun(int[][] a, int n) {
		//w为执行的层数
		int w, p;
		//x,y为p的取值范围
		int x, y;
		p = 0;
		
		//N阶方阵要执行N/2次循环赋值，每次赋值从主对角线开始，按逆时针依次递增赋值
		for (w = 0; w <= N / 2; w++) {
			
			//x, y为赋值的范围，注意不能给已经赋值过的再次赋值
			for (x = 0, y = N - 1; x <= y; x++, y = N-x-1) {
				//给第x列赋值
				for (p = x; p <= y; p++) {
					if (a[p][x] < 0) {
						a[p][x] = n++;
					}
				}
				
				//给y = N-x-1行赋值
				for (p = x; p <= y; p++) {
					if (a[y][p] < 0) {
						a[y][p] = n++;
					}
				}
				
				//给y = N-x-1列赋值
				for (p = x; p <= y; p++) {
					if (a[N-1-p][y] < 0) {
						a[N-1-p][y] = n++;
					}
				}
				
				//给x行赋值
				for (p = x; p <= y; p++) {
					if (a[x][N-1-p] < 0) {
						a[x][N-1-p] = n++;
					}
				}
			}
			
		}
	}
	
	/**输出*/
	public static void print(int[][] a) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				System.out.printf("%5d", a[i][j]);
			}
			System.out.println();
		}
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int[][] a = new int[100][100];
		int n = 1;
		while (true) {
			System.out.print("请输入N的值：");
			N = s.nextInt();
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					//全部初始化为-1，用于判断是否被赋值过
					a[i][j] = -1;
				}
			}
			fun(a, n);
			print(a);
			n = 1;
		}
	}

}

