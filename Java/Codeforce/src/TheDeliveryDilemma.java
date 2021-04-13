import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class TheDeliveryDilemma {
	static class Delivery implements Comparable<Delivery> {
		int courierTime;
		int petyaTime;
		@Override
		public int compareTo(Delivery o) {
			if(this.courierTime == o.courierTime)
				return this.petyaTime - o.petyaTime;
			return this.courierTime - o.courierTime;
		}
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		for (int tc = 0; tc < testCase; tc++) {
			int n = fs.nextInt();
			Delivery[] list = new Delivery[n];
			for(int i = 0; i < n; ++i) {
				list[i] = new Delivery();
				list[i].courierTime = fs.nextInt();
			}
			for(int i = 0; i < n; ++i)
				list[i].petyaTime = fs.nextInt();
			Arrays.sort(list);
			long[] suffixSum = new long[n + 1];
			suffixSum[0] = 0;
			for(int i = 1; i <= n; ++i)
				suffixSum[i] = suffixSum[i - 1] + list[i - 1].petyaTime;
			long ans = suffixSum[n];
			for(int i = 1; i <= n; ++i) {
				ans = Math.min(ans, Math.max(list[i - 1].courierTime, suffixSum[n] - suffixSum[i]));
			}
			System.out.println(ans);
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