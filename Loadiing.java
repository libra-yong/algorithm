package greedy;

import Sort.MergeSort;

/**
* @author: libra
* @address: github: https://github.com/libra-yong
* create on 2017-06-19
*/

/**
 * 最优装载问题
 * 有一批集装箱要装上一艘载重量为c的轮船.其中集装箱i的重量为w[i], 最优装载问题要求在体积不受限的情况下, 将尽可能多的集装箱装入轮船
 * */
public class Loadiing {
	public static class Element implements Comparable {
		float weight;	//物品重量
		int i;		//物品序号
		public Element(float ww, int ii) {
			weight = ww;
			i = ii;
		}
		
		public int compareTo(Object x) {
			float xw = ((Element)x).weight;
			if (weight < xw) {
				return -1;
			}
			if (weight == xw) {
				return 0;
			}
			return 1;
		}
	}
	
	/**
	 * 
	 * @param c 船的载重量
	 * @param weight 集装箱的重量
	 * @param x 解集
	 * */
	public static float loading(float c, float[] weight, int[] x) {
		int n = weight.length;
		//构建新的对象数组
		Element[] d = new Element[n];
		//初始化d的重量w[i]和序号i
		for (int i = 0; i < n; i++) {
			d[i] = new Element(weight[i], i);
		}
		
		MergeSort.mergeSort(d);
		float opt = 0;
		
		//初始化解集x为0,x[i]表示第i个物品是否装箱, 1表示装箱
		for (int i = 0; i < n; i++) {
			x[i] = 0;
		}
		
		for (int i = 0; i < n && d[i].weight <= c; i++) {
			x[d[i].i] = 1;	//d[i]是否装箱
			opt += d[i].weight;	//已装箱重量
			c -= d[i].weight;	//剩余可装箱重量
		}
		
		for (int i = 0; i < n; i++) {
			System.out.print(x[i] + " ");
		}
		return opt;
	}

	public static void main(String[] args) {
		float c = 200;
		float[] weight = new float[] {23, 39, 34, 100, 232, 122, 12};
		int[] x = new int[weight.length];
		loading(c, weight, x);
	}

}
