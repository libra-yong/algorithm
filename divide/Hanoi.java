package divide;
/**
 * 
 * create by libra天秤
 * */

/**
 * 
 * 汉诺塔问题
 * */
import java.util.Scanner;

public class Hanoi {
	/**
	 * 
	 * 将num个盘子从a塔移动到b塔, c做辅助塔
	 * */
	public static void hanoi(int num, int a, int b, int c) {
		if (num > 0) {
			hanoi(num - 1, a, c, b);
//			move(a, b); //move a to b
			System.out.println("move " + a + " to " + b);
			hanoi(num - 2, c, b, a);
		}
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int a, b, c;
		int num;
		a = 1; 
		b = 2;
		c = 3;
		System.out.print("请输入盘子数量：");
		num = s.nextInt();
		hanoi(num, a, b, c);

	}

}
