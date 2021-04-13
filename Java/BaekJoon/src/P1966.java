import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class P1966 {
	static class Data {
		int val;
		boolean isTarget;
		Data(int val, boolean isTarget) {
			this.val = val;
			this.isTarget = isTarget;
		}
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out, true);
		int tc = fs.nextInt();
		for(int t = 0; t < tc; ++t) {
			Queue<Data> q = new LinkedList<>();
			int n = fs.nextInt(), targetIndex = fs.nextInt();
			int[] cnt = new int[10];
			int[] priority = new int[100];
			for(int i = 0; i < n; ++i) {
				int v = fs.nextInt();
				priority[i] = v;
				cnt[priority[i]]++;
			}
			/*
			for(int i = 0; i < n; ++i) {
				out.println("n = " + i + "priority = " + priority[i] + "cnt = " + cnt[priority[i]]);
			}
			 */
			for(int i = 0; i < n; ++i) {
				boolean b = (i == targetIndex);
				q.add(new Data(i, b));
			}
			int cur = 1;
			while(!q.isEmpty()) {
				Data d = q.poll();
				boolean cont = false;
				for(int i = 9; priority[d.val] < i; --i) {
					if(0 < cnt[i]) {
						cont = true;
						break;
					}
				}
				if(cont) {
					q.add(d);
					continue;
				}
				if(d.isTarget) {
					out.println(cur);
					break;
				}
				++cur;
				--cnt[priority[d.val]];
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