import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class P1874 {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		Stack<Integer> stk = new Stack<>();
		List<Character> ans = new ArrayList<>();
		int n = fs.nextInt();
		stk.push(0);
		int cur = 1;
		for(int i = 0; i < n; ++i) {
			int v = fs.nextInt();
			while(stk.peek() < v) {
				//out.println("increase  :  " + stk.peek() + "   " + v + "    " + '+');
				if(v < cur) {
					out.println("NO");
					out.flush();
					return;
				}
				stk.add(cur++);
				ans.add('+');
			}
			while(v <= stk.peek()) {
				//out.println("decrease  :  " + stk.peek() + "   " + v + "    " + '-');
				stk.pop();
				ans.add('-');
			}
		}

		for(Character c : ans)
			out.println(c);
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