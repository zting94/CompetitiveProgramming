import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;
import java.util.logging.Logger;

public class BerlandCrossword2 {
	static boolean ans;
	static StringBuilder sb = new StringBuilder();
	static String key(int[] cur) {
		sb.setLength(0);
		for(int i = 0; i < 4; ++i)
			sb.append(cur[i]);
		return sb.toString();
	}
	static void dfs(int[] cur, int[] arr, int n, int limit, Set<String> set) {
		if(ans) return;
		boolean can = true;
		for(int i = 0; i < 4; ++i) {
			if(cur[i] != arr[i]) {
				can = false;
				break;
			}
		}
		if(can) {
			ans = true;
			return;
		}
		if(limit == 0) return;
		String k = key(cur);
		if(set.contains(k))
			return;
		set.add(k);
		for(int i = 0; i < 4; ++i) {
			if(cur[i] == n) continue;
			cur[i]++;
			if(cur[i] == n) {
				cur[(i + 3) % 4]++;
				cur[(i + 1) % 4]++;
			}
			if(cur[(i + 3) % 4] <= n && cur[(i + 1) % 4] <= n)
				dfs(cur, arr, n, limit - 1, set);
			if(cur[i] == n) {
				cur[(i + 3) % 4]--;
				cur[(i + 1) % 4]--;
			}
			cur[i]--;
		}
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		for (int tc = 0; tc < testCase; tc++) {
			ans = false;
			int n = fs.nextInt();
			int[] arr = new int[4];
			for(int i = 0; i < 4; ++i)
				arr[i] = fs.nextInt();
			int[] cur = new int[4];
			Set<String> set = new HashSet<>();
			dfs(cur, arr, n, n * 2 + (n - 2) * 2, set);
			if(ans) out.println("YES");
			else out.println("NO");
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