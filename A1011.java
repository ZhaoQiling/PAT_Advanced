import java.math.BigDecimal;
import java.util.Scanner;

public class A1011 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		BigDecimal ans = new BigDecimal("0.65");
		for(int i = 0; i < 3; i++) {
			int loc = 0;
			BigDecimal max = new BigDecimal(0);
			for(int j = 0; j < 3; j++) {
				BigDecimal val = new BigDecimal(in.next());
				if(val.compareTo(max) > 0) {
					max = val;
					loc = j;
				}
			}
			if(loc == 0) System.out.print("W ");
			else if(loc == 1) System.out.print("T ");
			else if(loc == 2) System.out.print("L ");
			ans = ans.multiply(max);
		}
		ans = ans.subtract(BigDecimal.ONE);
		ans = ans.multiply(new BigDecimal(2));
		System.out.printf("%.2f", ans.doubleValue());
	}

}
