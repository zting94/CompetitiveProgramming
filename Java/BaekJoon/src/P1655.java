import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class P1655 {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out, true);
		StringBuilder sb = new StringBuilder();
		int n = fs.nextInt();
		PriorityQueue<Integer> maxOfMins = new PriorityQueue<>(Comparator.reverseOrder());
		PriorityQueue<Integer> minOfMaxs = new PriorityQueue<>();
		for(int i = 0; i < n; ++i) {
			int v = fs.nextInt();
			minOfMaxs.add(v);
			maxOfMins.add(minOfMaxs.poll());
			if(minOfMaxs.size() + 1 < maxOfMins.size())
				minOfMaxs.add(maxOfMins.poll());
			sb.append(maxOfMins.peek() + "\n");
		}
		out.println(sb.toString());
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