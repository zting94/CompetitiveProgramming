import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class SortingBooks {
	static int ans;
	static void calculate(Map<Integer, Integer> count, int[] arr, List<Integer> picked) {
		Map<Integer, Integer> start = new HashMap<>();
		int pos = 0;
		for(int i = 0; i < picked.size(); ++i) {
			start.put(picked.get(i), pos);
			pos += count.get(picked.get(i));
		}
		int needMove = 0;
		for(int i = 0; i < arr.length && needMove <= ans; ++i) {
			int stPos = start.get(arr[i]);
			if(i < stPos || stPos + count.get(arr[i]) <= i)
				++needMove;
		}
		ans = Math.min(ans, needMove);
	}
	static void dfs(Map<Integer, Integer> count, int[] arr, int[] values, List<Integer> picked) {
		if(picked.size() == values.length) {
			calculate(count, arr, picked);
			return;
		}

		for(int i = 0; i < values.length; ++i) {
			if(picked.contains(values[i]))
				continue;
			picked.add(values[i]);
			dfs(count, arr, values, picked);
			picked.remove(picked.size() - 1);
		}
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		//int testCase = fs.nextInt();
		int testCase = 1;
		for (int tc = 0; tc < testCase; tc++) {
			int n = fs.nextInt();
			int[] arr = new int[n];
			Map<Integer, Integer> count = new HashMap<>();
			for(int i = 0; i < n; ++i) {
				int v = fs.nextInt();
				arr[i] = v;
				count.put(v, count.getOrDefault(v, 0) + 1);
			}
			int[] values = Arrays.stream(count.keySet().toArray()).mapToInt(i -> (int) i).toArray();
			ans = n;
			//System.out.println(count.size() + "\t" + values.length);
			List<Integer> picked = new ArrayList<>();
			dfs(count, arr, values, picked);
			System.out.println(ans);
		}
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