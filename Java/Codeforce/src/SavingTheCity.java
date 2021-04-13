import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class SavingTheCity {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		for (int tc = 0; tc < testCase; tc++) {
			int activatingCost = fs.nextInt(), placingCost = fs.nextInt();
			char[] city = fs.next().toCharArray();
			int n = city.length;
			int[] noAction = new int[n];
			int[] action = new int[n];
			int maxVal = (placingCost + activatingCost) * n;
			noAction[0] = city[0] == '0' ? 0 : activatingCost;
			action[0] = city[0] == '1' ? activatingCost : maxVal;
			for(int i = 1; i < n; ++i) {
				if(city[i] == '0') {
					noAction[i] = Math.min(noAction[i - 1], action[i - 1]);
					action[i] = Math.min(noAction[i - 1] + placingCost + activatingCost, action[i - 1] + placingCost);
				} else {
					noAction[i] = maxVal;
					action[i] = Math.min(action[i - 1], noAction[i - 1] + activatingCost);
				}
			}
			System.out.println(Math.min(noAction[n - 1], action[n - 1]));
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