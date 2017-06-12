package greedy;
/**
* @author: libra
* @address: github: https://github.com/libra-yong
* create on 2017-06-12
*/
import java.util.Scanner;
public class ISBN {
    public static long sum = 0;
    public static int count = 1;
    public static void main(String[] args) throws NumberFormatException {
        Scanner s = new Scanner(System.in);
        int x;
        String str = s.nextLine();
        String[] str2 = str.split("-");
        for (int i = 0; i < str2.length - 1; i++) {
            	char[] strChar = str2[i].toCharArray();
        		for (Character str3: strChar) {
                    x = Integer.parseInt(str3.toString());
                    sum += x * count;
                    count++;
                }
        }
       	x = Integer.parseInt(str2[3]);
        if ((sum % 11) == x) {
         	System.out.println("Right");   
        } else {
            System.out.println(str.substring(0, str.length()-1) + (sum % 11));
        }
    }
}