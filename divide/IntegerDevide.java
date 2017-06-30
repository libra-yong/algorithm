package divide;
/**
* @author: libra
* @address: github: https://github.com/libra-yong
* create on 2017-06-30
*/

/**
 * 
 * 整数划分问题
 * 正整数k不大于m的划分个数记作devide(n, m), 由如下递归关系
 * (1)divide(n, 1) = 1, n >= 1
 * 当最大加数k不大于1时, 任何正整数n只有一种划分形式, 即n=1+1+...+1;(n个1)
 * (2)divide(n, m) = divide(n, n), m >= n
 * 最大加数k实际上不能大于n, 因此q(1, m)=1
 * (3)divide(n, n) = 1 + divide(n, n-1)
 * 正整数n的划分由k=n的划分和k<=n-1的划分组成
 * (4)divide(n, m)=divide(n, m-1)+divide(n-m, m), n>m>1
 * 正整数n的最大加数k不大于m的划分(m的划分由k=m的划分和k<=m-1的划分组成)
 * 
 * 以上退出递归表达式
 * divide(n, m) = 1, n = m = 1
 * divide(n, m) = divide(n, n), n < m
 * divide(n, m) = 1 + divide(n, n-1), n = m
 * divide(n, m) = divide(n, m-1)+divide(n-m, m), n>m>1 
 * */
public class IntegerDevide {
	public static int divide(int n) {
		return divide(n, n);
	}
	public static int divide(int n, int m) {
		if ((n < 1) || (m < 1)) {
			return 0;
		}
		if ((n == 1) || (m == 1)) {
			return 1;
		}
		if (n < m) {
			return divide(n,n);
		}
		if (n == m) {
			return divide(n, m - 1) + 1;
		}
		return divide(n, m - 1) + divide(n - m, m);
	}
	public static void main(String[] args) {
		System.out.println(divide(6));
	}
}
