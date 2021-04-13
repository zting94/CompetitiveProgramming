import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class SearchingLocalMinimum {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		//int testCase = fs.nextInt();
		int testCase = 1;
		for (int tc = 0; tc < testCase; tc++) {
			int n = fs.nextInt();
			int[] arr = new int[n + 2];
			arr[0] = arr[n + 1] = Integer.MAX_VALUE;
			//TODO : binary search
			// n = 10
			// permutation
			// 1 2 8 9 10 4 7 5 6 3
			int left = 1, right = n;
			while(left < right) {
				int mid = (left + right) / 2;
				System.out.println("? " + mid);
				arr[mid] = fs.nextInt();
				System.out.println("? " + (mid + 1));
				arr[mid + 1] = fs.nextInt();
				if(arr[mid] < arr[mid + 1])
					right = mid;
				else
					left = mid + 1;
			}
			System.out.println("! " + left);
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