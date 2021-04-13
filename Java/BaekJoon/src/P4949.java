import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Stack;
import java.util.StringTokenizer;

public class P4949 {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out, true);
		outer : while(true) {
			String line = fs.nextLine();
			if(line.equals("."))
				break;
			Stack<Character> stk = new Stack<>();
			for(char c : line.toCharArray()) {
				if(c == '(' || c == '[') {
					stk.push(c);
				} else if(c == ')') {
					if(stk.isEmpty() || stk.peek() != '(') {
						out.println("no");
						continue outer;
					}
					stk.pop();
				} else if(c == ']') {
					if(stk.isEmpty() || stk.peek() != '[') {
						out.println("no");
						continue outer;
					}
					stk.pop();
				}
			}
			if(stk.isEmpty())
				out.println("yes");
			else
				out.println("no");
		}
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

		String nextLine() {
			try {
				return br.readLine();
			} catch(IOException e)  {
				e.printStackTrace();
				return "";
			}
		}

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