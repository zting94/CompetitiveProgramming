import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class P2667 {
	static final int[] dr = new int[]{-1, 1, 0, 0};
	static final int[] dc = new int[]{0, 0, -1, 1};
	static boolean isValid(int r, int c, int n) {
		if(r < 0 || c < 0 || n <= r || n <= c)
			return false;
		return true;
	}
	static int dfs(int[][] arr, int r, int c, int n) {
		if(!isValid(r, c, n) || arr[r][c] == 0)
			return 0;
		arr[r][c] = 0;
		int result = 1;
		for(int i = 0; i < 4; ++i) {
			int rr = r + dr[i], cc = c + dc[i];
			result += dfs(arr, rr, cc, n);
		}
		return result;
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		int n = fs.nextInt();
		int[][] arr = new int[n][n];
		for(int i = 0; i < n; ++i) {
			String s = fs.next();
			for(int j = 0; j < s.length(); ++j) {
				arr[i][j] = s.charAt(j) - '0';
			}
		}
		List<Integer> result = new ArrayList<>();
		for(int r = 0; r < n; ++r) {
			for(int c = 0; c < n; ++c) {
				if(arr[r][c] == 1) {
					result.add(dfs(arr, r, c, n));
				}
			}
		}
		Collections.sort(result);
		System.out.println(result.size());
		for(int i : result)
			System.out.println(i);
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