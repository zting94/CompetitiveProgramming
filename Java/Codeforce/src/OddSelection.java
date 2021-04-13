import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class OddSelection {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testcase = fs.nextInt();
		for (int tc = 0; tc < testcase; tc++) {
			int n = fs.nextInt(), pick = fs.nextInt();
			int oddCnt = 0, evenCnt = 0;
			for(int i = 0; i < n; ++i) {
				int v = fs.nextInt();
				if(v % 2 == 1) ++oddCnt;
				else ++evenCnt;
			}
			int needEvenPick = Math.min(pick - 1, evenCnt);
			int needOddPick = pick - needEvenPick;
			if(needOddPick % 2 == 0) {
				++needOddPick;
			}
			if(needOddPick <= oddCnt && needOddPick <= pick)
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