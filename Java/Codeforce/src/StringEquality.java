import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class StringEquality {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		outer : for (int tc = 0; tc < testCase; tc++) {
			int n = fs.nextInt(), k = fs.nextInt();
			int[] cntA = new int[27];
			int[] cntB = new int[27];
			char[] a = fs.next().toCharArray();
			char[] b = fs.next().toCharArray();
			for(int i = 0; i < n; ++i) {
				cntA[a[i] - 'a']++;
				cntB[b[i] - 'a']++;
			}
			for(int i = 25; i >= 0; --i) {
				cntA[i] += cntA[i + 1];
				cntB[i] += cntB[i + 1];
				if(cntA[i] > cntB[i] || ((cntB[i] - cntA[i]) % k) != 0) {
					System.out.println("NO");
					continue outer;
				}
			}
			System.out.println("YES");
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