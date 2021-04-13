import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class ReverseBinaryStrings2 {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		int maxN = 100001;
		for (int tc = 0; tc < testCase; tc++) {
			int n = fs.nextInt();
			char[] str = fs.next().toCharArray();
			int[][] oneZero = new int[n + 1][2];
			int[][] zeroOne = new int[n + 1][2];
			int maxVal = 100005;
			if(str[0] == '0') {
				oneZero[0][0] = maxVal;
				oneZero[0][1] = 1;
				zeroOne[0][0] = 0;
				zeroOne[0][1] = maxVal;
			} else {
				oneZero[0][0] = 0;
				oneZero[0][1] = maxVal;
				zeroOne[0][0] = maxVal;
				zeroOne[0][1] = 1;
			}
			for(int i = 1; i < n; ++i) {
				// oneZero should be 1
				// zeroOne should be 0
				if(i % 2 == 0) {
					if(str[i] == '1') {
						oneZero[i][0] = Math.min(oneZero[i - 1][0], oneZero[i - 1][1]);
						oneZero[i][1] = maxVal;
						zeroOne[i][0] = maxVal;
						zeroOne[i][1] = Math.min(zeroOne[i - 1][0] + 1, zeroOne[i - 1][1]);
					} else {
						oneZero[i][0] = maxVal;
						oneZero[i][1] = Math.min(oneZero[i - 1][0] + 1, oneZero[i - 1][1]);
						zeroOne[i][0] = Math.min(zeroOne[i - 1][0], zeroOne[i - 1][1]);
						zeroOne[i][1] = maxVal;
					}

				// oneZero should be 0
				// zeroOne should be 1
				} else {
					if(str[i] == '1') {
						oneZero[i][0] = maxVal;
						oneZero[i][1] = Math.min(oneZero[i - 1][0] + 1, oneZero[i - 1][1]);
						zeroOne[i][0] = Math.min(zeroOne[i - 1][0], zeroOne[i - 1][1]);
						zeroOne[i][1] = maxVal;
					} else {
						oneZero[i][0] = Math.min(oneZero[i - 1][0], oneZero[i - 1][1]);
						oneZero[i][1] = maxVal;
						zeroOne[i][0] = maxVal;
						zeroOne[i][1] = Math.min(zeroOne[i - 1][0] + 1, zeroOne[i - 1][1]);
					}
				}
			}
			System.out.println(Math.min(Math.min(zeroOne[n - 1][0], zeroOne[n - 1][1]),
										Math.min(oneZero[n - 1][0], oneZero[n - 1][1])));
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