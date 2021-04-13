import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class StrangeList {
	static int getModCount(int num, int mod) {
		int cnt = 0;
		while(num % mod == 0) {
			++cnt;
			num /= mod;
		}
		return cnt;
	}
	public static void main(String[] args) {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		for (int tc = 0; tc < testCase; tc++) {
			int n = fs.nextInt(), mod = fs.nextInt();
			int[] arr = new int[n];
			long[] sum = new long[n + 1];
			int[] count = new int[n];
			int minCountIdx = 0;
			for(int i = 0; i < n; ++i) {
				arr[i] = fs.nextInt();
				sum[i + 1] = sum[i] + arr[i];
				count[i] = getModCount(arr[i], mod);
				if(count[i] < count[minCountIdx]) minCountIdx = i;
			}
			long ans = ((long)count[minCountIdx] + 1) * sum[n];
			ans += sum[minCountIdx];
			System.out.println(ans);
		}
	}

	/* TLE
	static class Data {
		int val;
		int count;
		public Data(int val, int count) {
			this.val = val;
			this.count = count;
		}
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		for (int tc = 0; tc < testCase; tc++) {
			int n = fs.nextInt(), mod = fs.nextInt();
			Queue<Data> q = new LinkedList<>();
			long sum = 0;
			for(int i = 0; i < n; ++i) {
				int v = fs.nextInt();
				q.add(new Data(v, 1));
				sum += v;
			}
			while(!q.isEmpty()) {
				Data d = q.poll();
				if(d.val % mod != 0)
					break;
				int nextVal = d.val / mod;
				int addCnt = d.val / nextVal;
				sum += (long)nextVal * addCnt * d.count;
				q.add(new Data(nextVal, addCnt));
			}
			System.out.println(sum);
		}
	}
	 */
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