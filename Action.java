package greedy;

import java.util.Scanner;

/**
* @author: libra
* @address: github: https://github.com/libra-yong
* create on 2017-06-12
*/
/**
*n个活动E={1,2,..,n}，都要求使用同一公共资源（如演讲会场等）。且在同一时间仅一个活动可使用该资源。i属于[si,f(i)), 
s(i)为起始时间, f(i)为结束时间。s(i)<f(i)活动i和j相容: s(i)>=f(j)或s(j) > =f(i)

*
*/
//贪心算法并不总能求得问题的整体最优解。但对于活动安排问题，贪心算法却总能求得的整体最优解，即它最终所确定的相容活动集合A的规模最大。这个结论可以证明
public class Action {
	//选择具有最早结束时间的相容活动加入，使剩余的可安排时间最大，以安排尽可能多的活动
	//当输入的活动已按结束时间的非减序排列,从第一个活动开始,按顺序进行活动. 若下一个活动开始时间大于前一个活动则安排活动,否则不安排
	//算法只需O(n)时间安排n个活动，使最多的活动能相容地使用公共资源
	public static void action() {
		int[] s = new int[]{1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
		int[] f = new int[]{4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
		boolean[] a = new boolean[11];
		a[0] = true;
		int j = 0;
		for (int i = 1; i < s.length; i++) {
			if (s[i] >= f[j]) {
				//若后面活动开始时间大于已安排活动时间则安排后面活动
				a[i] = true;
				j = i;
			} else {
				a[i] = false;
			}
		}
		for (int i = 0; i < s.length; i++) {
			if (a[i] == true) {
				System.out.println(s[i] + "---" + f[i]);
			}
		}
	}
	
	
	public static void main(String[] args) {
		action();
		
	}

}
