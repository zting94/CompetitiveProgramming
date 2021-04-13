import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class MaximumWidth {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = 1;
		for (int tc = 0; tc < testCase; tc++) {
			int n = fs.nextInt(), m = fs.nextInt();
			char[] s = fs.next().toCharArray();
			char[] t = fs.next().toCharArray();
			List<Integer> left = new ArrayList<>();
			List<Integer> right = new ArrayList<>();
			for(int i = 0, j = 0; i < n && j < m; ++i) {
				if(s[i] == t[j]) {
					left.add(i);
					++j;
				}
			}
			for(int i = n - 1, j = m - 1; i >= 0 && j >= 0; --i) {
				if(s[i] == t[j]) {
					right.add(i);
					--j;
				}
			}
			int ans = 1;
			for(int i = 0; i < m - 1; ++i) {
				ans = Math.max(ans, right.get(m - i - 2) - left.get(i));
				//System.out.println(i + "\t" + (m - i - 2) + "\t" + right.get(m - i - 2) + "\t" + left.get(i));
			}
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