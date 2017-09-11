import java.io.IOException;
import java.util.LinkedList;
import java.util.ArrayList;
public class A1014 {
	public static int hour = 7;
	public static int min = 59;
	public static ArrayList<LinkedList<Integer>> windows = null;
	public static boolean[] isVis = null;
	public static int n = 0;
	public static boolean pass(int t) {
		hour += (min + t) / 60;
		min = (min + t) % 60;
		if(hour >= 999 && min > 0)
			return false;
		return true;
	}
	public static int cho() {
		int ans = 0;
		int min =Integer.MAX_VALUE;
		for(int i = 0; i < n; i++) {
			int len = windows.get(i).size();
			if(len < min) {
				min = len;
				ans = i;
			}
		}
		return ans;
	}
	
    public static void main(String[] args) throws IOException{
        Reader.init(System.in);

        n = Reader.nextInt();
        int m = Reader.nextInt();
        int k = Reader.nextInt();
        int q = Reader.nextInt();
        
        windows = new ArrayList<>();
        for(int i = 0; i < n; i++) {
        	windows.add(new LinkedList<Integer>());
        }
        int[] t = new int[k]; 
        for(int i = 0; i < k; i++) {
            t[i] = Reader.nextInt();
        }
        
        int[] sv = new int[k];
        boolean[] isVis = new boolean[k];
        int[] begin = new int[k];
        for(int i = 0; i < k; i++) {
            sv[i] = -1;
            isVis[i] = false;
            begin[i] = -1;
        }
        
        int nPro = 0;
        while(pass(1)) {
            for(int i = 0; i < n; i++) {
                LinkedList<Integer> que = windows.get(i);
                if(que.isEmpty())
                    continue;
                if(begin[que.getFirst()] == -1) {
                	begin[que.getFirst()] = hour * 60 + min;
                }
                if(--t[que.getFirst()] == 0) {
                    sv[que.getFirst()] = hour * 60 + min;
                    que.removeFirst();
                    nPro--;
                }
            }
            
            for(int i = 0; i < k; i++) {
                if(nPro >= n * m)
                    break;
                if(isVis[i])
                    continue;
                int c = cho();
                windows.get(c).add(i);
                nPro++;
                isVis[i] = true;
//                System.out.println("" + (i + 1)+ " join " + hour + ":" + min);
            }
        }

        for(int i = 0; i < q; i++) {
        	int temp = Reader.nextInt() - 1;
        	if(temp > k || temp < 0) {
        		System.out.println("Sorry");
        		continue;
        	}
            int val = sv[temp];
        	if(val == -1) {
        		System.out.println("Sorry");
        		continue;
        	}
            if(begin[temp] >=  1020) {
                System.out.println("Sorry");
                continue;
            }
            System.out.printf("%02d:%02d\n", val / 60, val % 60);
        }
    }

}
