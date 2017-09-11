import java.io.IOException;

public class A1009 {
	
	public static void main(String[] args) throws IOException {
		Reader.init(System.in);
		double[] aCoe = new double[1010];
		double[] bCoe = new double[1010];
//		for(int i = 0; i < 1010; i++) {
//			aCoe[i] = (double) 0;
//			bCoe[i] = (double) 0;
//		}
		int k = Reader.nextInt();
		for(int i = 0; i < k; i++) {
			int exp = Reader.nextInt();
			aCoe[exp] = Reader.nextDouble();
		}
		k = Reader.nextInt();
		for(int i = 0; i < k; i++) {
			int exp = Reader.nextInt();
			bCoe[exp] = Reader.nextDouble();
		}
		int nAns = 0;
		double[] ansCoe = new double[1001000];
		for(int a = 0; a <= 1000; a++) {
			for(int b = 0; b <= 1000; b++) {
				ansCoe[a + b] += aCoe[a] * bCoe[b];
			}
		}
		for(int i = 1000000; i >= 0; i--) {
			if(Double.compare(0, ansCoe[i]) != 0) {
				nAns++;
			}
		}
		System.out.print(nAns);
		for(int i = 1000000; i >= 0; i--) {
			if(Double.compare(ansCoe[i], 0) == 0)
				continue;
			else {
				System.out.printf(" %d %.1f", i, ansCoe[i]);
			}
		}
	}

}
