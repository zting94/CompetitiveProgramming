import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

//TODO: rename to Main
public class P4963 {
	static int W, H;
	static final int[] dh = {-1, 1, 0, 0, -1, -1, 1, 1};
	static final int[] dw = {0, 0, -1, 1, -1, 1, -1, 1};
	static boolean isValid(int h, int w) {
		return h >= 0 && w >= 0 && H > h && W > w;
	}
	static void dfs(int[][] matrix, int h, int w) {
	    if(!isValid(h, w) || matrix[h][w] != 1) {
	        return;
		}
	    matrix[h][w] = 0;
	    for (int i = 0; i < 8; ++i) {
	    	dfs(matrix, h + dh[i], w + dw[i]);
		}
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out, true);
		while(true) {
		    W = fs.nextInt();
		    H = fs.nextInt();
			if(W == 0 && H == 0) {
				break;
			}
			int[][] matrix = new int[H][W];
			for (int h = 0; h < H; ++h) {
			    for (int w = 0; w < W; ++w) {
			    	matrix[h][w] = fs.nextInt();
				}
			}
			int ans = 0;
			for (int h = 0; h < H; ++h) {
				for (int w = 0; w < W; ++w) {
				    if(matrix[h][w] == 1) {
				        ++ans;
				        dfs(matrix, h, w);
					}
				}
			}
			out.println(ans);
		}
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