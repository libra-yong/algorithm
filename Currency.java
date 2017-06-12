package greedy;

import java.util.*;
/**
* @author: libra
* @address: github: https://github.com/libra-yong
* create on 2017-06-12
*/
public class Currency {
	
	//时间复杂度o(n)
	public static void currency() {
		Scanner input = new Scanner(System.in);
		int i, j, n, money, a;
		//币种, 0不算
		int[] b = new int[]{0, 100, 50, 20, 10, 5, 2, 1};
		int[] s = new int[]{0, 0, 0, 0, 0, 0, 0, 0};
		
		n = input.nextInt();	//n个工资
		for (i = 1; i <= n; i++) {
			//输入工资
			money = input.nextInt();
			//注意j是从1开始的, 数组b的号位为0
			//对每个人的工资，用“贪婪”的思想，先尽量多地取大面额的币种，由大面额到小面额币种逐渐统计
			for (j = 1; j <= 7; j++) {
				//获取最大的张数
				a = money / b[j];
				s[j] = s[j] + a;
				money = money - a * b[j];
			}
		}
		//输出也是从1开始
		for (i = 1; i <= 7; i++) {
			System.out.println(b[i] + " --- " + s[i]);
		}
	}
	public static void main(String[] args) {
		currency();

	}

}
