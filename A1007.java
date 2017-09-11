import java.util.Scanner;
import java.util.ArrayList;
public class A1007 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int nNum = in.nextInt();
		ArrayList<Integer> arr = new ArrayList<Integer>();
		boolean allNegative = true;
		int thisSum = 0;
		int ansSum = -1;
		int thisBegin = 0;
		int ansBegin = 0;
		int end = 0;
		for(int i = 0; i < nNum; i++)
		{
			int val = in.nextInt();
			arr.add(val);
			if(val >= 0) allNegative = false;
			thisSum += val;
			if(thisSum < 0)
			{
				thisSum = 0;
				thisBegin = i + 1;
			}
			else if(thisSum > ansSum)
			{
				ansSum = thisSum;
				ansBegin = thisBegin;
				end = i;
			}
		}
		if(false == allNegative)
			System.out.print(ansSum + " " + arr.get(ansBegin) + " " + arr.get(end));
		else
			System.out.print(0 + " " + arr.get(0) + " " + arr.get(arr.size() - 1));
	}

}
