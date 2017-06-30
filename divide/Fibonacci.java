package divide;
/**
* @author: libra
* @address: github: https://github.com/libra-yong
* create on 2017-06-30
*/

/**
 * Fibonacci数列
 * */
public class Fibonacci {
	public static int fibonacci(int n) {
		if (n <= 1) {
			return 1;
		}
		return (fibonacci(n-1)+fibonacci(n-2));
	}

	public static void main(String[] args) {
		System.out.println(fibonacci(6));
	}

}
