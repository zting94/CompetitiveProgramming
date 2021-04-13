import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Journey {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		for (int tc = 0; tc < testCase; tc++) {
			int n = fs.nextInt();
			String s = fs.next();
			int[] dpleft = new int[n + 1];
			dpleft[0] = 0;
			for(int i = 1; i <= n; ++i) {
				if(s.charAt(i - 1) == 'R')
					dpleft[i] = 0;
				else {
					if(i >= 2 && s.charAt(i - 2) == 'R')
						dpleft[i] = dpleft[i - 2] + 2;
					else
						dpleft[i] = 1;
				}
			}
			int[] dpright = new int[n + 1];
			dpright[n] = 0;
			for(int i = n - 1; i >= 0; --i) {
				if(s.charAt(i) == 'L')
					dpright[i] = 0;
				else {
					if(i < n - 1 && s.charAt(i + 1) == 'L')
						dpright[i] = dpright[i + 2] + 2;
					else
						dpright[i] = 1;
				}
			}
			for(int i = 0; i <= n; ++i)
				out.print((dpleft[i] + dpright[i] + 1) + " ");
			out.println();
		}
		out.close();
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