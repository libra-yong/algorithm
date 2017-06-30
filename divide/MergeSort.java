package divide;
/**
* @author: libra天秤
* create on 2017年6月3日 下午3:10:46
* github: https://github.com/libra-yong/demo
*/
public class MergeSort {
	public static Comparable[] mergeSort(Comparable[] a) {
		Comparable[] b = new Comparable[a.length];
		int s = 1;
		while (s < a.length) {
			mergePass(a, b, s);
			s += s;
			mergePass(b, a, s);
			s += s;
		}
//		for (int i = 0;i < a.length; i++) {
//			 System.out.println(a[i]);
//		}
		return a;
	}
	
	public static void mergePass(Comparable[] x, Comparable[] y, int s) {
		int i = 0;
		while (i <= x.length - 2 * s) {
			merge(x, y, i, i + s - 1, i + 2 * s - 1);
			i = i + 2 * s;
		}
		if (i + s < x.length) {
			merge(x, y, i, i + s - 1, x.length - 1);
 		} else {
 			for (int j = i; j < x.length; j++) {
 				y[j] = x[j];
 			}
 		}
	}
	
	public static void merge(Comparable[] c, Comparable[] d, int l, int m, int r) {
		int i = l;
		int j = m + 1;
		int k = l;
		while ((i <= m) && (j <= r)) {
			if (c[i].compareTo(c[j]) <= 0) {
				d[k++] = c[i++];
			} else {
				d[k++] = c[j++];
			}
		}
		if (i > m) {
			for (int q = j; q <= r; q++) {
				d[k++] = c[q];
			}
		} else {
			for (int q = i; q <= m; q++) {
				d[k++] = c[q];
			}
		}
	}
	
	public static void main(String[] args) {
		Comparable[] a = {1, 3, 43, 43, 3, 4, 24, 24, 434};
		Comparable[] b = mergeSort(a);
		for (Comparable x: b) {
			System.out.println(x);
		}
		
	}

}
