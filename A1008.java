import java.io.IOException;

public class A1008 {

	public static void main(String[] args) throws IOException {
		Reader.init(System.in);
		Integer n = Reader.nextInt();
		int sum = 0;
		int loc = 0;
		for(int i = 1; i <= n; i++) {
			int next = Reader.nextInt();
			if(next > loc)
				sum += 6 * (next - loc);
			else if(next < loc)
				sum += 4 * (loc - next);
			loc = next;
		}
		sum += n * 5;
		System.out.println(sum);

	}

}
