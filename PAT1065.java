import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.StringTokenizer;

class Reader {
		static BufferedReader reader;
		static StringTokenizer tokenizer;

		static void init(InputStream input) {
			reader = new BufferedReader(
					new InputStreamReader(input));
			tokenizer = new StringTokenizer("");
		}

		static String next() throws IOException{
			while(!tokenizer.hasMoreTokens()) {
				tokenizer = new StringTokenizer(
						reader.readLine());
			}
			return tokenizer.nextToken();
		}
		static int nextInt() throws IOException {
	        return Integer.parseInt( next() );
	    }

	    static double nextDouble() throws IOException {
	        return Double.parseDouble( next() );
	    }
        static BigInteger nextBigInteger() throws IOException {
            return new BigInteger(next());
        }
}

public class Hello {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Reader.init(System.in);
		int nCase = Reader.nextInt();
		for(int i = 1; i <= nCase; i++) {
			BigInteger a = Reader.nextBigInteger();
			BigInteger b = Reader.nextBigInteger();
			BigInteger c = Reader.nextBigInteger();
			System.out.print("Case #" + i + ": ");
			if(a.add(b).compareTo(c) > 0)
				System.out.println("true");
			else
				System.out.println("false");
		}
	}

}
