import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class XXXXX {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int tc = fs.nextInt();
		for (int t = 0; t < tc; t++) {
			int n = fs.nextInt(), x = fs.nextInt();
			int[] arr = new int[n];
			int sum = 0;
			for (int i = 0; i < n; i++) {
				arr[i] = fs.nextInt();
				sum += arr[i];
			}
			int ans = -1;
			for(int curSum = sum, right = n - 1; right >= 0; --right) {
				if(curSum % x != 0) {
					ans = Math.max(ans, right + 1);
					break;
				}
				curSum -= arr[right];
			}
			for(int curSum = sum, left = 0; left < n; ++left) {
				if(curSum % x != 0) {
					ans = Math.max(ans, n - left);
					break;
				}
				curSum -= arr[left];
			}
			System.out.println(ans);
		}
		/*
		for (int t = 0; t < tc; t++) {
			int n = fs.nextInt(), x = fs.nextInt();
			int[] arr = fs.readArray(n);
			int[] sum = new int[n + 1];
			for(int i = 1; i <= n; ++i)
				sum[i] += (sum[i - 1] + arr[i - 1]) % x;
			int ans = -1;
			for(int l = 0; l < n; ++l) {
				for(int r = n; r >= l + 1; --r) {
					int v = sum[r] - sum[l];
					if(v % x != 0) {
						ans = Math.max(ans, r - l);
						break;
					}
				}
			}
			System.out.println(ans);
		}
		 */
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