import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class AdvertisingAgency {
	static final long mod = 1000000007L;
	static long binomial(long[][] cache, int n, int r) {
		if(r <= 0 || n <= r)
			return 1;
		if(cache[n][r] != 0)
			return cache[n][r];
		return cache[n][r] = (binomial(cache, n - 1, r - 1) + binomial(cache, n - 1, r)) % mod;
	}
	static long getBinomial(int n, int r) {
		if(r <= 0 || n <= r)
			return 1;
		long[][] cache = new long[n + 1][r + 1];
		return binomial(cache, n, r) % mod;
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		for (int tc = 0; tc < testCase; tc++) {
			int n = fs.nextInt(), k = fs.nextInt();
			int[] arr = fs.readArray(n);
			TreeMap<Integer, Integer> mp = new TreeMap<>();
			for (int i = 0; i < n; i++)
				mp.put(arr[i], mp.getOrDefault(arr[i], 0) + 1);
			NavigableSet<Integer> descendingKeySet = mp.descendingKeySet();
			Iterator<Integer> it = descendingKeySet.iterator();
			int canChoose = 0;
			int lastSame = 0;
			int remain = k;
			while(remain > 0) {
				int canPick = mp.get(it.next());
				if(remain - canPick >= 0) {
					canChoose += canPick;
					remain -= canPick;
				} else {
					lastSame = canPick;
					break;
				}
			}
			out.println(getBinomial(canChoose, k - remain) * getBinomial(lastSame, remain));
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