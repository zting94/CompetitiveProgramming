import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Stack;
import java.util.StringTokenizer;

public class P1918 {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out, true);
		StringBuilder sb = new StringBuilder();
		Stack<Character> stk = new Stack<>();
		String str = fs.next();
		for(char c : str.toCharArray()) {
			if(Character.isAlphabetic(c))
				sb.append(c);
			else if(c == '(')
				stk.push(c);
			else if(c == '+' || c == '-') {
				while(!stk.isEmpty() && stk.peek() != '(')
					sb.append(stk.pop());
				stk.push(c);
			} else if(c == '*' || c == '/') {
				while(!stk.isEmpty() && stk.peek() != '(' && stk.peek() != '+' && stk.peek() != '-')
					sb.append(stk.pop());
				stk.push(c);
			} else {
				while(!stk.isEmpty() && stk.peek() != '(')
					sb.append(stk.pop());
				stk.pop();
			}
		}
		while(!stk.isEmpty())
			sb.append(stk.pop());
		System.out.println(sb.toString());
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