import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class LevelStatistics {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int tc = fs.nextInt();
		for (int t = 0; t < tc; t++) {
			int n = fs.nextInt();
			int prevP = 0, prevC = 0;
			boolean success = true;
			for(int i = 0; i < n; ++i) {
				int curP = fs.nextInt(), curC = fs.nextInt();
				if(curC > curP || curC < prevC || curP < prevP)
					success = false;
				if(prevP > curP && prevC < curC)
					success = false;
				int c = curC - prevC;
				int p = curP - prevP;
				if(p < c)
					success = false;
				prevC = curC;
				prevP = curP;
			}
			if(success)
				System.out.println("YES");
			else
				System.out.println("NO");
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