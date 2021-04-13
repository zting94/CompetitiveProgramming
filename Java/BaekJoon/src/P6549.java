import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class P6549 {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out, true);
		while(true) {
			int N = fs.nextInt();
			if(N == 0)
				break;
			List<Long> list = new ArrayList<>();
			list.add(0L);
			for(int i = 0; i < N; ++i)
				list.add(fs.nextLong());
			list.add(0L);
			long ans = 0;
			Stack<Integer> stk = new Stack<>();
			stk.add(0);
			for(int i = 1; i < list.size(); ++i) {
				while(!stk.isEmpty() && list.get(i) < list.get(stk.peek())) {
					long h = list.get(stk.peek());
					stk.pop();
					long w = (long)i - stk.peek() - 1L;
					ans = Math.max(ans, w * h);
				}
				stk.push(i);
			}
			out.println(ans);
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