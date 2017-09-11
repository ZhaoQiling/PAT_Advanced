import java.io.IOException;
import java.util.LinkedList;
public class A1004 {
	public static void main(String[] args) throws IOException{
		Reader.init(System.in);
		//the number of nodes in a tree
		int n = Reader.nextInt();
		//the number of non-leaf nodes
		int m = Reader.nextInt();
		
		Integer[][] arr = new Integer[110][110];
		for(int i = 0; i < 110; i++)
			for(int j = 0; j < 110; j++)
				arr[i][j] = -1;
		
		Integer[] h = new Integer[110];
		h[1] = 0;
		for(int i = 0; i < m; i++) {
			int f = Reader.nextInt();
			int nChild = Reader.nextInt();
			for(int j = 0; j < nChild; j++) {
				Integer c = Reader.nextInt();
				arr[f][j] = c;
//				h[c] = h[f] + 1;
			}
		}
		for(int i = 1; i < 110; i++) {
			for(int j = 0; arr[i][j] != -1; ++j) {
				h[arr[i][j]] = h[i] + 1;
			}
		}
			
//		for(int i = 0; i < 110; i++) {
//			System.out.println("" + i + " " + h[i]);
//		}
		LinkedList<Integer> que = new LinkedList<>();
		que.add(1);
		int cntLs = 0;
		int level = 0;
//		System.out.println(que.isEmpty());
		while(que.isEmpty() == false) {
			int head = que.getFirst();
			//System.out.println("head is " + head);
			if(h[head] != level) {
				System.out.print(cntLs + " ");
				level = h[head];
				cntLs = 0;
			}
			boolean hasChild = false;
			for(int i = 0; arr[head][i] != -1; i++) {
				que.add(arr[head][i]);
				hasChild = true;
			}
			if(hasChild == false) {
				cntLs++;
			}
			que.removeFirst();
		}
		System.out.println(cntLs);
	}

}
