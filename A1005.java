import java.io.IOException;
import java.util.Scanner;

public class A1005 {

	public static void main(String[] args) throws IOException {
	        String[] num = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	        Scanner in = new Scanner(System.in);
	        
	        String n = in.next();
	        String[] arr = n.split("");
	        Integer sum = 0;
	        for(int i = 0; i < arr.length; i++)
	            sum += Integer.parseInt(arr[i]);
	        
	        String[] s = sum.toString().split(""); 

	        for(int i = 0; i < s.length; i++) {
	            if(i != 0) System.out.print(" ");
	            System.out.print(num[Integer.parseInt(s[i])]);
	        }
	        
	        in.close();
	}

}
