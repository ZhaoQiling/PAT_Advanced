import java.io.IOException;

public class A1006 {
	public static int ntime(String s) {
		String[] hsm = s.split(":");
		return Integer.parseInt(hsm[0]) * 60 * 60
				+ Integer.parseInt(hsm[1]) * 60
				+ Integer.parseInt(hsm[2]);
	}
	public static void main(String[] args) throws IOException {
		Reader.init(System.in);
		Integer m = Reader.nextInt();
		String lock = null;
		String unlock = null;
		int start = Integer.MAX_VALUE;
		int end = 0;
		for(int i = 0; i < m; ++i) {
			String temp = Reader.next();
			int a = ntime(Reader.next());
			if(a < start) {
				start = a;
				lock = temp;
			}
			int b = ntime(Reader.next());
			if(b > end) {
				end = b;
				unlock = temp;
			}
		}
		System.out.println(lock + " " + unlock);
	}

}
