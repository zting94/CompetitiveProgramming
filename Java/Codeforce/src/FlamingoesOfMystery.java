import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class FlamingoesOfMystery {
	static PrintWriter out = new PrintWriter(System.out);
	static FastScanner fs = new FastScanner();
	static int ask(int l, int r) {
		out.println("? " + l + " " + r);
		out.flush();

		return fs.nextInt();
	}
	public static void main(String[] args)  {
		int testCase = 1;
		for (int tc = 0; tc < testCase; tc++) {
			int n = fs.nextInt();
			int[] arr = new int[n + 1];
			arr[n] = ask(1, n);
			arr[1] = arr[n] - ask(2, n);
			int sum = arr[1];
			for(int i = 2; i < n; ++i) {
				arr[i] = ask(i - 1, i) - arr[i - 1];
				sum += arr[i];
			}
			arr[n] -= sum;
			out.println("!");
			out.flush();
			for(int i = 1; i <= n; ++i) {
				out.print(arr[i] + " ");
				out.flush();
			}
			out.println();
			out.flush();
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