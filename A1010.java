import java.io.IOException;
import java.util.Scanner;

public class A1010 {
	public static long pow(long a, long b) {
		if(b == 0)
			return 1;
		else {
			long ans = 1;
			for(int i = 0; i < b; i++)
				ans *= a;
			return ans;
		}
	}
	public static long getLong(String s, long radix) {
		long ans = 0;
		for(int i = s.length() - 1; i >= 0; i--) {
			long val = 0;
			char c = s.charAt(i);
			if(c >= '0' && c <= '9')
				val = c - '0';
			else if(c >= 'a' && c <= 'z')
				val = c - 'a' + 10;
			ans += pow(radix, s.length() - 1 - i) * val;
		}
		return ans;
	}
	public static int findMaxCh(String s) {
		int max = 0;
		for(int i = 0; i < s.length(); i++) {
			int val = 0;
			char c = s.charAt(i);
			if(c >= '0' && c <= '9')
				val = c - '0';
			else if(c >= 'a' && c <= 'z')
				val = c - 'a' + 10;
			if(val > max) max = val;
		}
		return max + 1;
	}

	public static void main(String[] args) throws IOException{
		Scanner in = new Scanner(System.in);
		String n1 = in.next();
		String n2 = in.next();
		int tag = in.nextInt();
		if(tag == 2) {
			String temp = n1;
			n1 = n2;
			n2 = temp;
		}
		long radix = in.nextLong();
		long v1 = getLong(n1, radix);
		long left = findMaxCh(n2);
		long right = Math.max(left, v1) + 1;
		long ans = -1;
		while(left <= right) {
			long mid = (left + right) / 2;
//			System.out.println("left is " + left + " right is " + right + " mid is " + mid);
			long sv = getLong(n2, mid);
			if(sv < 0) {
				right = mid - 1;
				continue;
			}
			else if(sv < v1) {
				left = mid + 1;
			}
			else if(sv > v1) {
				right = mid - 1;
			}
			else {
				ans = mid;
				break;
			}
		}
		
		if(ans == -1)
			System.out.println("Impossible");
		else
			System.out.println(ans);
		in.close();
	}

}
