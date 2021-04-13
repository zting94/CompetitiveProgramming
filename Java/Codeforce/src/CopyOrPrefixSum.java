import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class CopyOrPrefixSum {
	static int MOD = (int)Math.pow(10, 9) + 7;
	static int dp(Map<Integer, Map<Long, Integer>> cache, long[] arr, int curIdx, long sum) {
		//System.out.println("curIdx : " + curIdx + "\tlastPicked : " + lastPicked + "\tsum : " + sum);
		if(curIdx == arr.length)
			return 1;
		if(cache.get(curIdx).containsKey(sum))
			return cache.get(curIdx).get(sum);
		Map<Long, Integer> mp = cache.get(curIdx);
		long v = arr[curIdx] - sum;
		//System.out.println("\tv : " + v);
		int result = dp(cache, arr, curIdx + 1, sum + arr[curIdx]);
		if(v != arr[curIdx])
			result += dp(cache, arr, curIdx + 1, sum + v);
		mp.put(sum, result % MOD);
		return result % MOD;
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		for (int tc = 0; tc < testCase; tc++) {
			int n = fs.nextInt();
			long[] arr = fs.readLongArray(n);
			Map<Integer, Map<Long, Integer>> cache = new HashMap<>();
			for(int i = 0; i < n ;++i)
				cache.put(i, new HashMap<>());
			out.println(dp(cache, arr, 1, arr[0]));
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
		long[] readLongArray(int n) {
			long[] a = new long[n];
			for(int i = 0; i < n; ++i)
				a[i] = nextLong();
			return a;
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