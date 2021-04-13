import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.function.BiFunction;
import java.util.function.Function;

//TODO: rename to Main
public class P10026 {
	static final char dummy = '.';
	static final int[] dr = {-1, 1, 0, 0};
	static final int[] dc = {0, 0, -1, 1};
    @FunctionalInterface
	interface TriFunction<T, U, V, R> {
        R apply(T t, U u, V v);
	}
    static void dfs1(char[][] arr, int r, int c, int n, char same, BiFunction<Character, Character, Boolean> func) {
        if (!isValid(r, c, n) || !func.apply(arr[r][c], same)) {
        	return;
		}
        arr[r][c] = dummy;
        for (int i = 0; i < 4; ++i) {
        	dfs1(arr, r + dr[i], c + dc[i], n, same, func);
		}
	}
	static void dfs2(char[][] arr, int r, int c, int n, TriFunction<Character, Character, Character, Boolean> func) {
    	if (!isValid(r, c, n) || !func.apply(arr[r][c], 'R', 'G')) {
    		return;
		}
    	arr[r][c] = dummy;
    	for (int i = 0; i < 4; ++i) {
    		dfs2(arr, r + dr[i], c + dc[i], n, func);
		}
	}
	static boolean isValid(int r, int c, int n) {
		return r >= 0 && c >= 0 && n > r && n > c;
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out, true);
		int n = fs.nextInt();
		char[][] arr = new char[n][n];
		char[][] arr2 = new char[n][n];
		for (int i = 0; i < n; ++i) {
			String s = fs.next();
			for (int j = 0; j < n; ++j) {
				arr[i][j] = arr2[i][j] = s.charAt(j);
			}
		}
		int ans1 = 0, ans2 = 0;
		for (int r = 0; r < n; ++r) {
			for (int c = 0; c < n; ++c) {
			    if (arr[r][c] != dummy) {
			        ++ans1;
			        dfs1(arr, r, c, n, arr[r][c], (x, y) -> x == y);
				}

			    if (arr2[r][c] == 'B') {
			        ++ans2;
			        dfs1(arr2, r, c, n, arr2[r][c], (x, y) -> x == y);
				} else if (arr2[r][c] != dummy) {
			    	++ans2;
					dfs2(arr2, r, c, n, (x, y, z) -> x == y || x == z);
				}
			}
		}
		out.println(ans1 + " " + ans2);
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