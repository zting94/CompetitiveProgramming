import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class ArrayDestruction {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		outer : for (int tc = 0; tc < testCase; tc++) {
			int n = fs.nextInt();
			int arrLen = 2 * n;
			int[] arr = fs.readArray(arrLen);
			ruffleSort(arr);
			TreeMap<Integer, Integer> mp = new TreeMap<>();
			for(int i = 0; i < arrLen; ++i) {
				mp.put(arr[i], mp.getOrDefault(arr[i], 0) + 1);
			}
			size : for(int sz = 0; sz < arrLen - 1; ++sz) {
				TreeMap<Integer, Integer> check = new TreeMap<>(mp);
				int x = arr[sz] + arr[arrLen - 1];
				List<Integer> ans = new ArrayList<>();
				for(int i = 0; i < n; ++i) {
					if(check.lastEntry().getValue() == 0)
						check.remove(check.lastKey());
					int y = check.lastKey();
					check.put(y, check.get(y) - 1);
					if(check.get(y) == 0)
						check.remove(y);
					if(!check.containsKey(x - y))
						continue size;
					check.put(x - y, check.get(x - y) - 1);
					if(check.get(x - y) == 0)
						check.remove(x - y);
					ans.add(y);
					ans.add(x - y);
					x = Math.max(y, x - y);
				}
				System.out.println("YES\n" + (arr[sz] + arr[arrLen - 1]));
				for(int i = 0; i < arrLen; i += 2)
					System.out.println(ans.get(i) + " " + ans.get(i + 1));
				continue outer;
			}
			System.out.println("NO");
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