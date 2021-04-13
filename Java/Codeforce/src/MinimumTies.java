import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class MinimumTies {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		for (int tc = 0; tc < testCase; tc++) {
			int n = fs.nextInt();
			if(n % 2 == 1) {
				int sz = n * (n - 1) / 2;
				for (int i = 0; i < sz; i++) {
					out.print((i % 2 == 0 ? 1 : -1) + " ");
				}
			} else {
				int[][] grid = new int[n][n];
				for(int i = 0; i < n; i += 2) {
					grid[i][i + 1] = grid[i + 1][i] = 0;
					for(int j = i + 2; j < n; j += 2) {
						grid[i][j] = 1;
						grid[i][j + 1] = -1;
						grid[i + 1][j] = -1;
						grid[i + 1][j + 1] = 1;
					}
				}
				for(int i = 0; i < n; ++i)
					for(int j = i + 1; j < n; ++j)
						out.print(grid[i][j] + " ");
			}
			out.println();
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