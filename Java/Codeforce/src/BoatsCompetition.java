import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class BoatsCompetition {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int tc = fs.nextInt();
		for (int t = 0; t < tc; t++) {
			int n = fs.nextInt();
			int[] arr = fs.readArray(n);
			boolean[][] chk = new boolean[51][101];
			int[] cnt = new int[101];
			int ans = 0;
			for(int i = 0; i < n - 1; ++i) {
				for(int j = i + 1; j < n; ++j) {
					int sum = arr[i] + arr[j];
					if(!chk[i][sum] && !chk[j][sum]) {
						cnt[sum]++;
						chk[i][sum] = true;
						chk[j][sum] = true;
						ans = Math.max(ans, cnt[sum]);
					}
				}
			}
			System.out.println(ans);
		}
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