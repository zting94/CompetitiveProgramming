import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;
import java.util.zip.CheckedInputStream;

public class MaxMedian {
	static boolean isMedian(int[] arr, int median, int k, int n) {
		int[] diff = new int[n];
		int[] prefix = new int[n + 1];
		for(int i = 0; i < n; ++i)
			if(median <= arr[i]) diff[i] = 1;
			else diff[i] = -1;
		for(int i = 1; i <= n; ++i)
			prefix[i] = prefix[i - 1] + diff[i - 1];
		int min = 0;
		for(int i = k; i <= n; ++i) {
			min = Math.min(min, prefix[i - k]);
			if(prefix[i] - min > 0)
				return true;
		}
		return false;
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = fs.nextInt(), k = fs.nextInt();
		int[] arr = fs.readArray(n);
		int l = 1, r = n;
		int ans = 1;
		while(l <= r) {
			int m = (l + r) / 2;
			if(isMedian(arr, m, k, n)) {
				ans = m;
				l = m + 1;
			} else {
				r = m - 1;
			}
		}
		System.out.println(ans);
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