package divide;
/**
* @author: libra
* @address: github: https://github.com/libra-yong
* create on 2017-06-30
*/
public class Ackerman {
	public static int ackerman(int m) {
		return ackerman(m, m);
	}
	public static int ackerman(int m, int n) {
		if (m == 1 && n == 0) {
			return 2;
		} else if (m == 0 && n >= 0){
			return 1;
		} else if (m >= 2 && n ==0) {
			return m+2;
		} else if (m >= 1 && n >= 1) {
			return ackerman(ackerman(m-1, n), n-1);
		}
		return -1;
	}

	public static void main(String[] args) {
		System.out.println(ackerman(3));
	}

}
