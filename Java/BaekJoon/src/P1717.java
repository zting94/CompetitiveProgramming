import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class P1717 {
	static int find(int[] parent, int a) {
		if(parent[a] == a)
			return a;
		return parent[a] = find(parent, parent[a]);
	}
	static void merge(int[] parent, int a, int b) {
		int aa = find(parent, a);
		int bb = find(parent, b);
		if(a < b) parent[bb] = aa;
		else parent[aa] = bb;
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out, true);
		StringBuilder sb = new StringBuilder();
		int n = fs.nextInt(), m = fs.nextInt();
		int[] parent = new int[n + 1];
		for(int i = 0; i <= n; ++i) parent[i] = i;
		for(int i = 0; i < m; ++i) {
			int op = fs.nextInt(), a = fs.nextInt(), b = fs.nextInt();
			if(op == 0) merge(parent, a, b);
			else {
				int aa = find(parent, a);
				int bb = find(parent, b);
				if(aa == bb) sb.append("YES\n");
				else sb.append("NO\n");
			}
		}
		out.print(sb.toString());
		out.flush();
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