/*
这里写了一些有用的函数
create by libra天秤
*/

//选择排序
public static void selectSort(int[] number) {
	int m; 
	for (int i = 0; i < number.length - 1; i++) {
		m = i;
		for (int j = i + 1; j < number.length; j++) {
			if (number[j] < number[m]) {
				m = j;
			}
			}
		if (i != m) {
			swap(number[i], number[m]);
		}
		
		System.out.print("第 " + (i+1) + " 次排序：");
		for (int k = 0; k < number.length; k++) {
			System.out.print(number[k] + " ");
		}
		System.out.println();
	}
}

//判断方阵是否是幻方
public static boolean judge(int[][] a) {
	int[][] sum = new int[2][a.length];
	int sum1, sum2;
	sum1 = sum2 = 0;
	for (int i = 0; i < a.length; i++) {
		for (int j = 0; j < a.length; j++) {
			//0代表行，sum[0][i]表示第i行之和
			sum[0][i] += a[i][j];
			//1代表列，sum[1][i]表示第i列之和
			sum[1][i] += a[j][i];
			
			//对角线之和
			if (i == j) {
				//左对角线
				sum1 += a[i][j];
				//右对角线
				sum2 += a[j][2-i];
			}
		}
	}
	
	
	for (int i = 0; i < a.length; i++) {
		if (sum[0][i] == sum[1][i]) {
			if (sum1 == sum[0][i]) {
				if (sum1 == sum2) {
					//每行之和 = 每列之和 = 对角线之和时返回true
					return true;
				}
				
			}
		}
	}
	return false;
}

//求阶乘n!
public static int factorial(int n) {
	for (int i = n - 1; i > 0; i--) {
		n *= i;
	}
	return n;
}

//判断是否是素数，若是则返回true
public static boolean findPrime(int number) {
	int i = 2;
	while (i <= (number - 1)) {
		if(number % i == 0) {
			return false;
		}
		i++;
	}
	return true;
}

//判断是否为奇数，若是则返回true
public static boolean findOdd(int number) {
	if ((number + 1) % 2 == 0) {
		return true;
	}
	return false;
}


//判断是否是偶数，若是返回true
public static boolean findEvent(int number) {
	if ((number % 2) == 0) {
		return true;
	}
	return false;
}