import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class ReverseBinaryStrings {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		int tc = fs.nextInt();
		for (int t = 0; t < tc; t++) {
			int n = fs.nextInt();
			String s = fs.next();
			int cnta = 0, cntb = 0;
			for(int i = 0; i < s.length(); ++i) {
				if(i % 2 == 0) {
					if(s.charAt(i) == '0')
						++cnta;
					else
						++cntb;
				} else {
					if(s.charAt(i) == '1')
						++cnta;
					else
						++cntb;
				}
			}
			System.out.println(Math.min(cnta, cntb) / 2);
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