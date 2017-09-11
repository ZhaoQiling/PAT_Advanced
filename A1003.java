import java.io.IOException;

public class A1003 {
	public static void main(String[] args) throws IOException {
		Reader.init(System.in);
        int n = Reader.nextInt();
        int m = Reader.nextInt();
        int c1 = Reader.nextInt();
        int c2 = Reader.nextInt();
        int[] weight = new int[n];
        for(int i = 0; i < n; i++){
            weight[i] = Reader.nextInt();
        }
        int[][] e = new int[n][n];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                e[i][j] = Integer.MAX_VALUE;
        for(int i = 0; i < m; i++){
            int x = Reader.nextInt();
            int y = Reader.nextInt();
            int z = Reader.nextInt();
            e[x][y] = e[y][x] = z;
        }

        int[] dis = new int[n];
        for(int i = 0; i < n; i++)
            dis[i] = Integer.MAX_VALUE;
        int[] num = new int[n];
        int[] w = new int[n];
        
        num[c1] = 1;
        dis[c1] = 0;
        w[c1] = weight[c1];
        
        boolean[] isVis = new boolean[n];
//        isVis[c1] = true;
        for(int i = 0; i < n; i++){
        	int u = -1;
            int min = Integer.MAX_VALUE;
            for(int j = 0; j < n; j++){
                if(isVis[j]) continue;
                if(dis[j] < min) {
                	min = dis[j];
                	u = j;
                }
            }
//            System.out.println("u is " + u);
            isVis[u] = true;
            
            for(int v = 0; v < n; v++) {
            	if(e[u][v] == Integer.MAX_VALUE)
            		continue;
            	if(e[u][v] + dis[u] < dis[v]) {
            		dis[v] = e[u][v] + dis[u];
            		num[v] = num[u];
            		w[v] = w[u] + weight[v];
            	}
            	else if(e[u][v] + dis[u] == dis[v]) {
            		num[v] += num[u];
            		if(w[v] < w[u] + weight[v]) 
            			w[v] = w[u] + weight[v];
            	}
            }
        }
        System.out.println(num[c2] + " " + w[c2]);
    }

}