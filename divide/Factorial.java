package divide;
/**
* @author: libra
* @address: github: https://github.com/libra-yong
* create on 2017-06-30
*/

/**
 * 
 * 阶乘函数
 * */
public class Factorial {
	public static int factorial(int n) {
		if (n == 0) {
			return 1;
		}
		return n * factorial(n-1);
	}
	
	public static void main(String[] args) {
		System.out.println(factorial(3));
	}

}
