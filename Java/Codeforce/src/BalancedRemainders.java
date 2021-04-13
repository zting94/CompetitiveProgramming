import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class BalancedRemainders {
	static class Data {
		int zero;
		int one;
		int two;
		int cnt;
		public Data(int zero, int one, int two, int cnt) {
			this.zero = zero;
			this.one = one;
			this.two = two;
			this.cnt = cnt;
		}
		boolean isAnswer() {
			return zero == one && one == two;
		}
		long key() {
			return zero * 100000 + one * 1000 + two;
		}
		boolean canZeroOne() {
			return zero > one;
		}
		boolean canOneTwo() {
			return one > two;
		}
		boolean canTwoZero() {
			return two > zero;
		}
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		int[] tmp = new int[] {3, 1, 3, 0};
		for (int tc = 0; tc < testCase; tc++) {
			int n = fs.nextInt();
			int[] cnt = new int[3];
			for (int i = 0; i < n; i++) {
				int v = fs.nextInt();
				cnt[v % 3]++;
			}
			HashSet<Long> visited = new HashSet<>();
			Queue<Data> q = new LinkedList<>();
			q.add(new Data(cnt[0], cnt[1], cnt[2], 0));
			while(!q.isEmpty()) {
				Data d = q.poll();
				//System.out.println(d.zero + "\t" + d.one + "\t" + d.two);
				if(visited.contains(d.key()))
					continue;
				if(d.isAnswer()) {
					System.out.println(d.cnt);
					break;
				}
				visited.add(d.key());
				if(d.canZeroOne())
					q.add(new Data(d.zero - 1, d.one + 1, d.two, d.cnt + 1));
				if(d.canOneTwo())
					q.add(new Data(d.zero, d.one - 1, d.two + 1, d.cnt + 1));
				if(d.canTwoZero())
					q.add(new Data(d.zero + 1, d.one, d.two - 1, d.cnt + 1));
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