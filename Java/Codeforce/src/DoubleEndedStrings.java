import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class DoubleEndedStrings {
	static int matchedLength(char[] a, char[] b, int i, int j) {
		int result = 0;
		while(i < a.length && j < b.length && a[i] == b[j]) {
			++i;
			++j;
			++result;
		}
		return result;
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		for (int tc = 0; tc < testCase; tc++) {
			char[] a = fs.next().toCharArray();
			char[] b = fs.next().toCharArray();
			int maxLength = 0;
			for(int i = 0; i < a.length; ++i) {
				for(int j = 0; j < b.length; ++j) {
					maxLength = Math.max(maxLength, matchedLength(a, b, i, j));
				}
			}
			System.out.println(a.length + b.length - 2 * maxLength);
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