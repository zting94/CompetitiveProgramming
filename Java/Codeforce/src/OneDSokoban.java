import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class OneDSokoban {
	static int lowerBound(List<Integer> list, int key) {
		int idx = Collections.binarySearch(list, key);
		if(idx <= 0)
		    return Math.abs(idx + 1);
		while(idx >= 0 && list.get(idx) == key)
			--idx;
		if(idx <= 0)
		    return 0;
		if(list.get(idx) < key)
			++idx;
		return idx;
	}
	static int upperBound(List<Integer> list, int key) {
		int n = list.size();
		int idx = Collections.binarySearch(list, key);
		if(idx <= 0)
			return Math.abs(idx + 1);
		while(idx < n && list.get(idx) <= key)
			++idx;
		return idx;
	}

	static int solve(List<Integer> boxs, List<Integer> specials) {
	    int n = boxs.size();
	    int m = specials.size();
	    int[] onSpecial = new int[n + 1];
	    for(int i = 0; i < n; ++i) {
	    	int idx = lowerBound(specials, boxs.get(i));
	    	if(idx < m && specials.get(idx).intValue() == boxs.get(i).intValue())
	    		onSpecial[i] = 1;
		}
	    for(int i = n - 1; i >= 0; --i)
	    	onSpecial[i] += onSpecial[i + 1];
	    int ans = onSpecial[0];
	    for(int i = 0; i < m; ++i) {
	    	int leftIdx = lowerBound(boxs, specials.get(i));
	    	if(leftIdx <= 0)
	    		continue;
	    	ans = Math.max(ans, upperBound(specials, specials.get(i) + leftIdx) - i + onSpecial[leftIdx]);
		}
	    return ans;
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		for (int tc = 0; tc < testCase; tc++) {
			int n = fs.nextInt(), m = fs.nextInt();
			List<Integer> boxs = new ArrayList<>();
			List<Integer> negBoxs = new ArrayList<>();
			List<Integer> specials = new ArrayList<>();
			List<Integer> negSpecials = new ArrayList<>();
			for(int i = 0; i < n; ++i) {
				int v = fs.nextInt();
				if(v > 0) boxs.add(v);
				else negBoxs.add(-v);
			}
			for(int i = 0; i < m; ++i) {
				int v = fs.nextInt();
				if(v > 0) specials.add(v);
				else negSpecials.add(-v);
			}
			negBoxs.sort(Integer::compare);
			negSpecials.sort(Integer::compare);
			out.println(solve(boxs, specials) + solve(negBoxs, negSpecials));
		}
		out.close();
	}
	static void ruffleSort(int[] a) {
		int n = a.length;
		Random r = new Random();
		for(int i = 0; i < a.length; ++i) {
			int oi = r.nextInt(n), t = a[i];
			a[i] = a[oi];
			a[oi] = t;
		}
		Arrays.sort(a);
	}
	static void sort(int[] a)   {
		ArrayList<Integer> l = new ArrayList<>();
		for(int i : a) l.add(i);
		Collections.sort(l);
		for(int i = 0; i < a.length; ++i) a[i] = l.get(i);
	}
	static class FastScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");

		String next()   {
			while(!st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a = new int[n];
			for(int i = 0; i < n; ++i)
				a[i] = nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}
}