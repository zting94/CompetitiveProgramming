import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class GuessingTheGreatest {
	public static void main(String[] args) {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = fs.nextInt();
		int left = 1, right = n;

		while(left + 1 < right) {
			int mid = (left + right) / 2;
			System.out.println("? " + left + " " + right);
			int second = fs.nextInt();
			if(mid <= second) {
				System.out.println("? " + mid + " " + right);
				int midsecond = fs.nextInt();
				if(midsecond == second)
					left = mid;
				else
					right = mid;
			} else {
				System.out.println("? " + left + " " + mid);
				int midsecond = fs.nextInt();
				if(midsecond == second)
					right = mid;
				else
					left = mid;
			}
		}

		System.out.println("? " + left + " " + right);
		int v = fs.nextInt();
		int myans = (v == left) ? right : left;
		System.out.println("! " + myans);
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