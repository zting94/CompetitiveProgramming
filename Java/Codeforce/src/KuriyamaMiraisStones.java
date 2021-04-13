import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class KuriyamaMiraisStones {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = fs.nextInt();
		long[] arr = new long[n];
		for (int i = 0; i < n; i++)
			arr[i] = fs.nextLong();
		long[] sum = new long[n + 1];
		for (int i = 1; i <= n; i++)
			sum[i] += sum[i - 1] + arr[i - 1];
		long[] sortSum = new long[n + 1];
		ruffleSort(arr);
		for (int i = 1; i <= n; i++)
			sortSum[i] += sortSum[i - 1] + arr[i - 1];
		int nQuery = fs.nextInt();
		for (int q = 0; q < nQuery; q++) {
			int type = fs.nextInt(), l = fs.nextInt(), r = fs.nextInt();
			if(type == 1)
				System.out.println(sum[r] - sum[l - 1]);
			else
				System.out.println(sortSum[r] - sortSum[l - 1]);
		}
	}
	static void ruffleSort(long[] a) {
		int n = a.length;
		Random r = new Random();
		for(int i = 0; i < a.length; ++i) {
			int oi = r.nextInt(n);
			long t = a[i];
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