import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

//TODO: rename to Main
public class P1987 {
	static int ans;
	static int row;
	static int col;
	static final int[] dr = {-1, 1, 0, 0};
	static final int[] dc = {0, 0, -1, 1};
	static boolean isValid(int r, int c) {
		return r >= 0 && c >= 0 && row > r && col > c;
	}
	static int getOnMask(int mask, char c) {
	    return (mask | (1 << (c - 'a')));
	}
	static int getOffMask(int mask, char c) {
	    return (mask ^ (1 << (c - 'a')));
	}
	static boolean isOn(int mask, char c) {
	    return (mask & (1 << (c - 'a')))  != 0;
	}
	static void dfs(char[][] arr, int r, int c, int mask, int dist, boolean[][] visited) {
		if(!isValid(r, c) || visited[r][c] || isOn(mask, arr[r][c])) {
			return;
		}
		visited[r][c] = true;
		mask = getOnMask(mask, arr[r][c]);
		ans = Math.max(ans, dist);
		for (int i = 0; i < 4; ++i) {
			dfs(arr, r + dr[i], c + dc[i], mask, dist + 1, visited);
		}
		visited[r][c] = false;
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out, true);
		row = fs.nextInt();
		col = fs.nextInt();
		char[][] arr = new char[row][];
		for (int r = 0; r < row; ++r) {
			arr[r] = fs.next().toCharArray();
		}
		ans = Integer.MIN_VALUE;
		boolean[][] visited = new boolean[row][col];
		dfs(arr, 0, 0, 0, 1, visited);

		out.println(ans);
		out.close();
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