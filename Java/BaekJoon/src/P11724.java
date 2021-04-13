import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.StringTokenizer;

public class P11724 {
	static int find(int[] parent, int u) {
		if(parent[u] == u)
			return u;
		return parent[u] = find(parent, parent[u]);
	}
	static void merge(int[] parent, int u, int v) {
		int uu = find(parent, u);
		int vv = find(parent, v);
		if(uu == vv) return;
		if(u < v) parent[vv] = uu;
		else parent[uu] = vv;
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		int n = fs.nextInt(), m = fs.nextInt();
		int[] parent = new int[n];
		for(int i = 0; i < n; ++i)
			parent[i] = i;
		for(int i = 0; i < m; ++i) {
			int u = fs.nextInt(), v = fs.nextInt();
			merge(parent, --u, --v);
		}
		HashSet<Integer> h = new HashSet<>();
		for(int i = 0; i < n; ++i) {
			h.add(find(parent, i));
		}
		System.out.println(h.size());
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