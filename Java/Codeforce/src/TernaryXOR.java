import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class TernaryXOR {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int t = fs.nextInt();
		for (int tt = 0; tt < t; tt++) {
			int n = fs.nextInt();
			String x = fs.next();
			StringBuilder a = new StringBuilder();
			StringBuilder b = new StringBuilder();
			a.append((x.charAt(0) == '0') ? "0" : "1");
			b.append((x.charAt(0) == '2') ? "1" : "0");
			for(int i = 1; i < n; ++i) {
				if(x.charAt(i) == '0') {
					a.append("0");
					b.append("0");
				} else if(x.charAt(i) == '1') {
					if(a.compareTo(b) < 0) {
						a.append("1");
						b.append("0");
					} else {
						a.append("0");
						b.append("1");
					}
				} else {
					int v = a.compareTo(b);
					if(v < 0) {
						a.append("2");
						b.append("0");
					} else if(v == 0) {
						a.append("1");
						b.append("1");
					} else {
						a.append("0");
						b.append("2");
					}
				}
			}
			System.out.println(a.toString());
			System.out.println(b.toString());
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