import java.util.Scanner;
public class A1074{
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int first = in.nextInt();
		int nNode = in.nextInt();
		int kRe = in.nextInt();
		int[] data = new int[100010];
		int[] nextLoc = new int[100010];
		for(int i = 0; i < nNode; i++)
		{
			int temp = in.nextInt();
			data[temp] = in.nextInt();
			nextLoc[temp] = in.nextInt();
		}
		
		int[] list = new int[10010];
		int sum = 0;
		while(first != -1)
		{
			list[sum++] = first;
			first = nextLoc[first];
		}
		
		int[]  result = new int[100010];
		for(int i = 0; i < sum; i++)
		{
			result[i] = list[i];
		}
		
		for(int i = 0; i < (sum - sum  % kRe); i++)
		{
			result[i] = list[i / kRe * kRe + kRe - 1 - i % kRe];
		}
		
		for(int i = 0; i < sum - 1; i++)
			System.out.printf("%05d %d %05d\n", result[i], data[result[i]], result[i + 1]);
		System.out.printf("%05d %d -1\n", result[sum - 1], data[result[sum - 1]]);
		in.close();
	}
}