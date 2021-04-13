import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class FindTheSpruce {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		for (int tc = 0; tc < testCase; tc++) {
			int n = fs.nextInt(), m = fs.nextInt();
			char[][] matrix = new char[n + 1][m + 1];
			for(int r = 1; r <= n; ++r) {
				String s = fs.next();
				for (int c = 1; c <= m; ++c)
					matrix[r][c] = s.charAt(c - 1);
			}
			int[][] dp = new int[n + 2][m + 2];
			long ans = 0;
			for(int r = n; r > 0; --r) {
				for(int c = m; c > 0; --c) {
					//System.out.println("r = " + r + "\tc = " + c + "\tmatrix[r][c] = " + matrix[r][c]);
					if(matrix[r][c] == '.')
						continue;
					++ans;
					dp[r][c] = 1;
					int minSpruce = Integer.MAX_VALUE;
					for(int lowerC = c - 1; lowerC <= c + 1; ++lowerC) {
						minSpruce = Math.min(minSpruce, dp[r + 1][lowerC]);
					}
					if(minSpruce > 0) {
						ans += minSpruce;
						dp[r][c] = minSpruce + 1;
						//System.out.println("\tr = " + r + "\tc = " + c + "\tmatrix[r][c] = " + matrix[r][c] + "\tminSpruce = " + minSpruce);
					}
				}
			}
			/*
			for(int r = 0; r <= n; ++r) {
				for(int c = 0; c < m + 2; ++c) {
					System.out.print(dp[r][c] + " ");
				}
				System.out.print("\t");
				for(int t = 1; t <= m; ++t)
					System.out.print(matrix[r][t] + " ");

				System.out.println();
			}
			 */
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