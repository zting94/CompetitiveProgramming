import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class DistrictsConnection {
	static class Edge {
		int from;
		int to;
		Edge(int from, int to) {
			this.from = from + 1;
			this.to = to + 1;
		}
	}
	boolean isFullyConnected(boolean[] connected) {
		for(int i = 0; i < connected.length; ++i) {
			if(!connected[i])
				return false;
		}
		return true;
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		int testCase = fs.nextInt();
		for (int tc = 0; tc < testCase; tc++) {
			int n = fs.nextInt();
			int[] arr = fs.readArray(n);
			boolean[] connected = new boolean[n];
			Arrays.fill(connected, false);
			connected[0] = true;
			List<Edge> ans = new ArrayList<>();
			int secondFrom = 0;
			for(int i = 1; i < n; ++i) {
				if(arr[i] != arr[0]) {
					ans.add(new Edge(0, i));
					connected[i] = true;
					secondFrom = i;
				}
			}
			for(int i = 0; i < n; ++i) {
				if(!connected[i] && arr[i] != arr[secondFrom]) {
					ans.add(new Edge(secondFrom, i));
					connected[i] = true;
				}
			}
			if(ans.size() != n - 1) {
				System.out.println("NO");
			} else {
				System.out.println("YES");
				for(Edge e : ans) {
					System.out.println(e.from + " " + e.to);
				}
			}
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