import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class PermutationTransformation {
	static void fill(int[] arr, int[] ans, int left, int right, int v)  {
		if(right < left)
			return;
		int idx = left;
		for(int i = left; i <= right; ++i)
			if(arr[i] > arr[idx])
				idx = i;
		ans[idx] = v;
		fill(arr, ans, left, idx - 1, v + 1);
		fill(arr, ans, idx + 1, right, v + 1);
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		for (int tt = 0; tt < testCase; tt++) {
			int n = fs.nextInt();
			int[] arr = fs.readArray(n);
			int[] ans = new int[n];
			fill(arr, ans, 0, n - 1, 0);
			for(int i : ans)
				System.out.print(i + " ");
			System.out.println();
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