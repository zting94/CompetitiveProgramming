import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class RestoreModulo {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		outer : for (int tc = 0; tc < testCase; tc++) {
			int n = fs.nextInt();
			int[] arr = fs.readArray(n);
			if(n == 1) {
				System.out.println(0);
				continue;
			}
			int diff = arr[1] - arr[0];
			int maxVal = arr[0];
			Set<Integer> diffs = new HashSet<>();
			for(int i = 1; i < n; ++i) {
				int v = arr[i] - arr[i - 1];
				if(!diffs.contains(v)) {
					diffs.add(v);
				}
				maxVal = Math.max(arr[i], maxVal);
			}
			if(diffs.size() >= 3) {
				System.out.println(-1);
				continue;
			}
			int m = 0;
			boolean can = true;
			for(int v : diffs) {
				m += Math.abs(v);
				if(v != diff) {
					can = false;
				}
			}
			if(can) {
				System.out.println(0);
				continue;
			}
			while(m < maxVal) {
				m += m;
			}
			while(diff < 0) {
				diff += m;
			}
			for(int i = 1; i < n; ++i) {
				if(arr[i] != ((arr[i - 1] + diff) % m)) {
					System.out.println("-1");
					continue outer;
				}
			}
			System.out.println(m + " " + diff);
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