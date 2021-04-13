import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class RestoringThePermutation {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		for (int tc = 0; tc < testCase; tc++) {
			int n = fs.nextInt();
			int[] arr = fs.readArray(n);
			int[] minAns = new int[n];
			int[] maxAns = new int[n];
			//Arrays.fill(minAns, -1);
			//Arrays.fill(maxAns, -1);
			TreeSet<Integer> maxSet = new TreeSet<>();
			TreeSet<Integer> minSet = new TreeSet<>();
			for(int i = 1; i <= n; ++i) {
				maxSet.add(i);
				minSet.add(i);
			}
			minAns[0] = maxAns[0] = arr[0];
			maxSet.remove(arr[0]);
			minSet.remove(arr[0]);
			for(int i = 1; i < n; ++i) {
				if(arr[i - 1] != arr[i]) {
					maxAns[i] = minAns[i] = arr[i];
					maxSet.remove(arr[i]);
					minSet.remove(arr[i]);
				} else {
					minAns[i] = minSet.first();
					minSet.remove(minAns[i]);
					maxAns[i] = maxSet.floor(arr[i]);
					maxSet.remove(maxAns[i]);
				}
			}
			/*
			for(int i = 1; i < n; ++i) {
				if(arr[i - 1] != arr[i]) {
					maxAns[i] = minAns[i] = arr[i];
					maxSet.remove(arr[i]);
					minSet.remove(arr[i]);
				}
			}
			for(int i = 0; i < n; ++i) {
				if(minAns[i] == -1) {
					minAns[i] = minSet.first();
					minSet.remove(minAns[i]);
				}
				if(maxAns[i] == -1) {
					maxAns[i] = maxSet.floor(arr[i]);
					maxSet.remove(maxAns[i]);
				}
			}
			*/
			for(int i : minAns) {
				System.out.print(i + " ");
			}
			System.out.println();
			for(int i : maxAns) {
				System.out.print(i + " ");
			}
			System.out.println();
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