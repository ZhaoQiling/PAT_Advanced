import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.TreeMap;

public class A1012 {
	
	public static List<Map.Entry<Integer, Integer>> getList(TreeMap<Integer, Integer> mp){
		List<Map.Entry<Integer, Integer>> list = new ArrayList<Map.Entry<Integer, Integer>>(mp.entrySet());
//		Collection.sort(list, (o1, o2)->o1.getValue() - o1.getValue());
        Collections.sort(list,new Comparator<Map.Entry<Integer, Integer>>() {
            //…˝–Ú≈≈–Ú
            public int compare(Entry<Integer, Integer> o1,
                    Entry<Integer, Integer> o2) {
                return o2.getValue().compareTo(o1.getValue());
            }
        });
        return list;
	}
	public static void main(String[] args) throws IOException {
		Reader.init(System.in);
		int n = Reader.nextInt();
		int m = Reader.nextInt();
		TreeMap<Integer, Integer> amp = new TreeMap<Integer, Integer>();  
		TreeMap<Integer, Integer> cmp = new TreeMap<Integer, Integer>();  
		TreeMap<Integer, Integer> mmp = new TreeMap<Integer, Integer>();  
		TreeMap<Integer, Integer> emp = new TreeMap<Integer, Integer>();
		for(int i = 0; i < n; i++) {
			int key = Reader.nextInt();
			int c1 = Reader.nextInt();
			int m1 = Reader.nextInt();
			int e1 = Reader.nextInt();
			cmp.putIfAbsent(key, 0); cmp.put(key, c1);
			mmp.putIfAbsent(key, 0); mmp.put(key, m1);
			emp.putIfAbsent(key, 0); emp.put(key, e1);
			amp.putIfAbsent(key, 0); amp.put(key, c1 + m1 + e1);
		}
		List<Map.Entry<Integer, Integer>> clist = getList(cmp);
		List<Map.Entry<Integer, Integer>> mlist = getList(mmp);
		List<Map.Entry<Integer, Integer>> elist = getList(emp);
		List<Map.Entry<Integer, Integer>> alist = getList(amp);
		int order = 1;
		for(Map.Entry<Integer, Integer> e: clist){cmp.put(e.getKey(), order++);}
		order = 1;
		for(Map.Entry<Integer, Integer> e: mlist){mmp.put(e.getKey(), order++);}
		order = 1;
		for(Map.Entry<Integer, Integer> e: elist){emp.put(e.getKey(), order++);}
		order = 1;
		for(Map.Entry<Integer, Integer> e: alist){amp.put(e.getKey(), order++);}
		
//		System.out.println("c");
//		for(Map.Entry<Integer, Integer> e: clist){
//			System.out.println(e.getKey() + " " + e.getValue());
//		}
//		System.out.println("m");
//		for(Map.Entry<Integer, Integer> e: mlist){
//			System.out.println(e.getKey() + " " + e.getValue());
//		}
//		System.out.println("e");
//		for(Map.Entry<Integer, Integer> e: elist){
//			System.out.println(e.getKey() + " " + e.getValue());
//		}

		for(int i = 0; i < m; i++) {
			int q = Reader.nextInt();
			if(cmp.containsKey(q) == false) {
				System.out.println("N/A");
				continue;
			}
			int sv[] = {
				amp.get(q), cmp.get(q), mmp.get(q), emp.get(q)
			};
			int loc = 0;
			int front = Integer.MAX_VALUE;
			for(int j = 0; j < 4; j++) {
				if(sv[j] < front) {
					front = sv[j];
					loc = j;
				}
			}
			System.out.print(front + " ");
			if(loc == 0) System.out.println("A");
			else if(loc == 1) System.out.println("C");
			else if(loc == 2) System.out.println("M");
			else if(loc == 3) System.out.println("E");
		}
	}

}
