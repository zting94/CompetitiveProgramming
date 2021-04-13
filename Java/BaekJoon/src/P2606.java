import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class P2606 {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		int n = fs.nextInt(), m = fs.nextInt();
		List<Integer>[] list = new ArrayList[n];
		for(int i = 0; i < n; ++i)
			list[i] = new ArrayList<>();
		for(int i = 0; i < m; ++i) {
			int from = fs.nextInt(), to = fs.nextInt();
			list[from - 1].add(to - 1);
			list[to - 1].add(from - 1);
		}
		Queue<Integer> q = new LinkedList<>();
		boolean[] v = new boolean[n];
		int cnt = 0;
		q.add(0);
		while(!q.isEmpty()) {
			int idx = q.poll();
			if(v[idx])
				continue;
			++cnt;
			v[idx] = true;
			for(int i : list[idx])
				q.add(i);
		}
		System.out.println(cnt - 1);
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