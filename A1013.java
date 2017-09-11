import java.io.IOException;

public class A1013 {
	public static int n;
	public static int m;
	public static int k;
	public static int[] arr = null;
	
	public static int getFather(int n) {
		if(n == arr[n])
			return n;
		arr[n] = getFather(arr[n]);
		return arr[n];
	}
	public static boolean merge(int t1, int t2) {
		//ÇÜÔôÏÈÇÜÍõ
		t1 = getFather(t1);
		t2 = getFather(t2);
		if(t1 == t2)
			return true;
		if(t1 < t2)
			arr[t2] = arr[t1];
		else 
			arr[t1] = arr[t2];
		return false;
	}
	public static int getAns() {
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			if(arr[i] == i)
				cnt++;
		}
		return cnt;
	}
	public static void initArr() {
		for(int i = 1; i <= n; i++) {
			arr[i] = i;
		}
	}
	public static void main(String[] args) throws IOException {
		Reader.init(System.in);
		n = Reader.nextInt();
		m = Reader.nextInt();
		k = Reader.nextInt();
		arr = new int[n + 5];
		
		initArr();

		int[][] edge = new int[m + 5][2];
		for(int i = 0; i < m; i++) {
			edge[i][0] = (int) Reader.nextInt();
			edge[i][1] = (int) Reader.nextInt();
		}
		
		for(int i = 0; i < k; i++) {
			int check = (int) Reader.nextInt();
			for(int j = 0; j < m; j++) {
				int a = edge[j][0];
				int b = edge[j][1];
				if(a == check || b == check)
					continue;
				merge(a, b);
			}
			System.out.println(getAns() - 2);
			initArr();
		}
	}

}
