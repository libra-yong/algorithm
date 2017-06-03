/**
 * 
 * create by libra天秤
 * */

/**解数数字谜
 * 
 * 		a b c d e
 * 	  *      	a
 * 	---------------
 * 	  d d d d d d
 * 
 * */
import java.util.Scanner;

public class SolutinToNumber {

	public static void main(String[] args) {
		int a, b, c, d, e, f = 0;
		for (a = 3; a <= 9; a++) {
			for (d = 1; d <= 9; d++) {
				e = d * 100000 + d * 10000 + d * 1000 + d * 100 + d * 10 + d;
				if (e % a == 0) {
					f = e / a;
				}
				if (f / 10000 == a && f % 10 / 10 == a && f / 1000 == f % 10) {
					
				}
				System.out.println(f + " * " + a + " = " + e);
			}
		}
	}

}
