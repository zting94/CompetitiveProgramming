import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class TriangularPaths {
	static class Node implements Comparable<Node> {
		int r;
		int c;
		Node(int r, int c) {
			this.r = r;
			this.c = c;
		}
		public int compareTo(Node n) {
			if(this.r == n.r) {
				return Integer.compare(this.c, n.c);
			}
			return Integer.compare(this.r, n.r);
		}
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		for (int tc = 0; tc < testCase; tc++) {
			List<Node> nodes = new ArrayList<>();
			int n = fs.nextInt();
			int[] rows = fs.readArray(n);
			int[] cols = fs.readArray(n);
			for(int i = 0; i < n; ++i) {
				nodes.add(new Node(rows[i], cols[i]));
			}
			Collections.sort(nodes);
			int row = 1, col = 1;
			long ans = 0;
			for(Node node : nodes) {
				int needRow = node.r - row;
				int needCol = node.c - col;
			}
			System.out.println(ans);
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