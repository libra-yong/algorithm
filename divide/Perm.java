package divide;

import java.util.*;
import general.Swap;

/**
* @author: libra
* @address: github: https://github.com/libra-yong
* create on 2017-06-30
*/
public class Perm {
	public static void perm(Object[] list, int k, int m) {
		if (k == m) {
			for (int i = 0; i <= m; i++) {
				System.out.println(list[i]);
			}
			System.out.println();
		} else {
			for (int i = k; i <= m; i++) {
				Swap.swap(list, k, i);
				perm(list, k+1, m);
				Swap.swap(list, k, i);
			}
		}
	}
}
