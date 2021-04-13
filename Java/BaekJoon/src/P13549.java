import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class P13549 {
	static class Data implements Comparable<Data> {
		int x;
		int cnt;
		public Data(int x, int cnt) {
			this.x = x;
			this.cnt = cnt;
		}

		@Override
		public int compareTo(Data o) {
			return this.cnt - o.cnt;
		}
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out, true);
		int n = fs.nextInt(), k = fs.nextInt();
		boolean[] visited = new boolean[100001];
		Arrays.fill(visited, false);
		PriorityQueue<Data> q = new PriorityQueue<>();
		q.add(new Data(n, 0));
		while(!q.isEmpty()) {
			Data d = q.poll();
			if(d.x < 0 || 100000 < d.x || visited[d.x])
				continue;
			if(d.x == k) {
				System.out.println(d.cnt);
				break;
			}
			visited[d.x] = true;
			q.add(new Data(d.x * 2, d.cnt));
			q.add(new Data(d.x - 1, d.cnt + 1));
			q.add(new Data(d.x + 1, d.cnt + 1));
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