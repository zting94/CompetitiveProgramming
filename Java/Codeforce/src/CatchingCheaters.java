import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class CatchingCheaters {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		//int testCase = fs.nextInt();
		int testCase = 1;
		for (int tc = 0; tc < testCase; tc++) {
			int n = fs.nextInt(), m = fs.nextInt();
			char[] a = fs.next().toCharArray();
			char[] b = fs.next().toCharArray();
			int[][] dp = new int[n][m];
			int ans = 0;
			for(int i = 0; i < n; ++i) {
				for(int j = 0; j < m; ++j) {
					if(a[i] == b[j]) {
					    dp[i][j] = 2;
					    if(0 < i && 0 < j) {
					    	dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] + 2);
						}
					} else {
					    dp[i][j] = 0;
					    if(0 < i) {
					        dp[i][j] = Math.max(dp[i][j], dp[i - 1][j]);
						}
					    if(0 < j) {
					    	dp[i][j] = Math.max(dp[i][j], dp[i][j - 1]);
						}
					    dp[i][j] = Math.max(dp[i][j] - 1, 0);
					}
					ans = Math.max(ans, dp[i][j]);
				}
			}
			out.println(ans);
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