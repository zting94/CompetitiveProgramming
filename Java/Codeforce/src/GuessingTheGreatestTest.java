import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class GuessingTheGreatestTest {
	static int[] arr;
	static int ans() {
		int idx = 1;
		for(int i = 1; i < arr.length; ++i)
			if(arr[idx] < arr[i])
				idx = i;
		return idx;
	}
	static void buildTestArray(int n) {
		int[] tmp = new int[n];
		arr = new int[n + 1];
		for(int i = 0; i < n; ++i)
			tmp[i] = i + 1;
		Random r = new Random();
		for(int i = 0; i < n; ++i) {
			int oi = r.nextInt(n), t = tmp[i];
			tmp[i] = tmp[oi];
			tmp[oi] = t;
		}
		for(int i = 0; i < n; ++i)
			arr[i + 1] = tmp[i];
		/*
		System.out.print("\t\tarr  =  ");
		for(int i = 1; i <= n; ++i)
			System.out.print(arr[i] + " ");
		System.out.println();
		 */
	}
	static int query(int left, int right) {
		int maxVal = left;
		for(int i = left; i <= right; ++i)
			if(arr[maxVal] < arr[i])
				maxVal = i;
		int second = (left == maxVal ? right : left);
		for(int i = left; i <= right; ++i) {
			if(arr[second] < arr[i] && i != maxVal)
				second = i;
		}
		return second;
	}
	static boolean solve(int n) {
		buildTestArray(n);
		int left = 1, right = n;
		while(left + 1 < right) {
			int mid = (left + right) / 2;
			//System.out.println("? " + left + " " + right);
			//int second = fs.nextInt();
			int second = query(left, right);
			//System.out.println("queried = " + second + "\tmid = " + mid + "\tmidVal = " + arr[mid]);
			if(mid <= second) {
				//System.out.println("? " + mid + " " + right);
				//int midsecond = fs.nextInt();
				int midsecond = query(mid, right);
				//System.out.println("\tmid <= second queried = " + midsecond + "\tval = " + arr[midsecond]);
				if(midsecond == second)
					left = mid;
				else
					right = mid;
			} else {
				//System.out.println("? " + left + " " + mid);
				//int midsecond = fs.nextInt();
				int midsecond = query(left, mid);
				//System.out.println("\tsecond < mid queried = " + midsecond + "\tval = " + arr[midsecond]);
				if(midsecond == second)
					right = mid;
				else
					left = mid;
			}
			//System.out.println("\t\tupdated left = " + left + " right = " + right);
		}

		if(left == right) {
			System.out.println("left == right " + left + " " + right);
			return false;
		}
		int v = query(left, right);
		int myans = (v == left) ? right : left;
		int ans = ans();
		//System.out.println("left = " + left + "  right = " + right);
		System.out.println("myans = " + myans + "  ans = " + ans);
		return myans == ans;
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		for(int i = 1; i <= 1; ++i) {
			System.out.print("i = " + i + " ");
			for (int j = 2; j <= 100000; j++) {
				System.out.print("j = " + j + " ");
				if(!solve(j)) {
					System.out.println("FAIL");
					return;
				}
			}
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