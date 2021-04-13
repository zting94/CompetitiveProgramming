import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class AccidentalVictory {
	static class Pair implements Comparable<Pair> {
		int token;
		int playerNum;
		public Pair(int token, int playerNum) {
			this.token = token;
			this.playerNum = playerNum;
		}
		public int compareTo(Pair o) {
			return this.token - o.token;
		}
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		for (int tt = 0; tt < testCase; tt++) {
			int n = fs.nextInt();
			Pair[] arr = new Pair[n];
			long sum = 0;
			for(int i = 0; i < n; ++i) {
				int token = fs.nextInt();
				arr[i] = new Pair(token, i + 1);
				sum += token;
			}
			Arrays.sort(arr);
			ArrayList<Pair> ansList = new ArrayList<>();
				ansList.add(arr[n - 1]);
				for(int i = n - 2; i >= 0; --i) {
					sum -= arr[i + 1].token;
					if(sum < arr[i + 1].token)
						break;
					ansList.add(arr[i]);
				}
				ansList.sort((o1, o2) -> o1.playerNum - o2.playerNum);
				System.out.println(ansList.size());
				ansList.stream().forEach(p -> {
					System.out.print(p.playerNum + " ");
			});
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