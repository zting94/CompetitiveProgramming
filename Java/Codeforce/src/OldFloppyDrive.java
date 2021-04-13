import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class OldFloppyDrive {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		for (int tt = 0; tt < testCase; tt++) {
			int n = fs.nextInt(), nQuery = fs.nextInt();
			int[] arr = fs.readArray(n);
			long maxPrefixSum = arr[0], prefixSum = arr[0];
			TreeMap<Long, Integer> mp = new TreeMap<>();
			mp.put(maxPrefixSum, 0);
			for(int i = 1; i < n; ++i) {
				prefixSum += arr[i];
				if(prefixSum > maxPrefixSum) {
					mp.put(prefixSum, i);
					maxPrefixSum = prefixSum;
				}
			}
			for (int q = 0; q < nQuery; q++) {
				long target = fs.nextLong();
				if(target <= mp.lastKey()) {
					out.print(mp.ceilingEntry(target).getValue() + " ");
					continue;
				}
				if(prefixSum <= 0) {
					out.print(-1 + " ");
					continue;
				}
				long amount = target - mp.lastKey();
				long cycle = (amount + prefixSum - 1) / prefixSum;
				long ans = cycle * n + mp.ceilingEntry(target - prefixSum * cycle).getValue();
				out.print(ans + " ");
			}
			out.println();
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