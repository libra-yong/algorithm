package divide;
/**
* @author: libra
* @address: github: https://github.com/libra-yong
* create on 2017-06-30
*/

/**
 * 
 * 二分搜索法基本思想: 对于已排好的序列, 将n个元素分成两个区间, 比较x在哪个区间, x在哪个区间就就继续将那个区间分成两半, 再比较.
 * */
public class BinarySearch {
	/**
	 * 
	 * 假设数组a为非递减序排列
	 * */
	public static int binarySearch(int[] a, int x, int n) {
		int left = 0; 
		int right = n - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (x == a[mid]) {
				return mid;
			}
			if (x > a[mid]) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		return -1;
	}
	
	public static void main(String[] args) {
		int[] a = new int[] {1, 2, 3, 21, 23};
		System.out.println(binarySearch(a, 23, a.length));
	}

}
