import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class P1766 {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out, true);
		int n = fs.nextInt(), m = fs.nextInt();
		int[] topology = new int[n];
		Arrays.fill(topology, 0);
		ArrayList<Integer>[] next = new ArrayList[n];
		for(int i = 0; i < n; ++i)
			next[i] = new ArrayList<>();
		for(int i = 0; i < m; ++i) {
			int a = fs.nextInt() - 1, b = fs.nextInt() - 1;
			next[a].add(b);
			topology[b]++;
		}
		PriorityQueue<Integer> q = new PriorityQueue<>();
		for(int i = 0; i < n; ++i)
			if(topology[i] == 0)
				q.add(i);
		while(!q.isEmpty()) {
			int v = q.poll();
			System.out.print(v + 1 + " ");
			for(int k : next[v]) {
				topology[k]--;
				if(topology[k] == 0)
					q.add(k);
			}
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