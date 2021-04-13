import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Kanpsack {
	static class Data implements Comparable<Data> {
		int value;
		int originalIndex;
		Data(int value, int originalIndex) {
			this.value = value;
			this.originalIndex = originalIndex;
		}
		@Override
		public int compareTo(Data o) {
			return this.value - o.value;
		}
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		outer : for (int tc = 0; tc < testCase; tc++) {
			int n = fs.nextInt();
			long w = fs.nextLong();
			long half = (long)Math.ceil((double)w / 2);
			List<Data> arr = new ArrayList<>();
			for(int i = 0; i < n; ++i) {
				int val = fs.nextInt();
				arr.add(new Data(val, i + 1));
			}
			Collections.sort(arr, Collections.reverseOrder());
			long sum = 0;
			List<Integer> ans = new ArrayList<>();
			for(Data d : arr) {
				if(d.value > w) {
					continue;
				}
				if(half <= d.value) {
					System.out.println(1);
					System.out.println(d.originalIndex);
					continue outer;
				}
				long tmp = sum + d.value;
				if(tmp > w) {
					break;
				}
				ans.add(d.originalIndex);
				sum = tmp;
				if(sum >= half) {
					break;
				}
			}
			if(ans.isEmpty() || sum < half || w < sum) {
				System.out.println(-1);
			} else {
				System.out.println(ans.size());
				for(int idx : ans)
					System.out.print(idx + " ");
				System.out.println();
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