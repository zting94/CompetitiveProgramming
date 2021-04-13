import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Program {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		for (int tc = 0; tc < testCase; tc++) {
			int n = fs.nextInt(), nQuery = fs.nextInt();
			String s = fs.next();
			int[] maxl = new int[n + 1], minl = new int[n + 1], endl = new int[n + 1];
			int[] maxr = new int[n + 1], minr = new int[n + 1], endr = new int[n + 1];
			int curMax = 0, curMin = 0, cur = 0;
			for(int i = 0; i < n; ++i) {
				cur += (s.charAt(i) == '+') ? 1 : -1;
				curMax = Math.max(curMax, cur);
				curMin = Math.min(curMin, cur);
				maxl[i + 1] = curMax;
				minl[i + 1] = curMin;
				endl[i + 1] = cur;
			}
			curMax = curMin = cur = 0;
			for(int i = n - 1; i >= 0; --i) {
				cur += (s.charAt(i) == '-') ? 1 : -1;
				curMax = Math.max(curMax, cur);
				curMin = Math.min(curMin, cur);
				maxr[i] = curMax;
				minr[i] = curMin;
				endr[i] = cur;
			}
			for(int i = 0; i < nQuery; ++i) {
				int l = fs.nextInt() - 1, r = fs.nextInt();
				int preMax = maxl[l], preMin = minl[l];
				int postMax = endl[l] + maxr[r] - endr[r];
				int postMin = endl[l] + minr[r] - endr[r];
				System.out.println(Math.max(preMax, postMax) - Math.min(preMin, postMin) + 1);
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