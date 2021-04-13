import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class CheapDinner {
	static class Cost implements Comparable<Cost> {
		int idx;
		int cost;
		public Cost(int idx, int cost) {
			this.idx = idx;
			this.cost = cost;
		}
		public int compareTo(Cost rhs) {
			return this.cost - rhs.cost;
		}
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int[] ns = fs.readArray(4);
		List<Cost>[] costList = new List[4];
		HashMap<Integer, HashSet<Integer>>[] hash = new HashMap[3];
		for(int i = 0; i < 4; ++i) {
			costList[i] = new ArrayList<>();
			for(int t = 0; t < ns[i]; ++t)
				costList[i].add(new Cost(t, fs.nextInt()));
		}
		for(int i = 0; i < 3; ++i) {
			hash[i] = new HashMap<>();
			for(int tt = 0; tt < ns[i]; ++tt)
				hash[i].put(tt, new HashSet<>());
			int m = fs.nextInt();
			for (int t = 0; t < m; t++) {
				int from = fs.nextInt() - 1, to = fs.nextInt() - 1;
				hash[i].get(from).add(to);
			}
		}
		for (int prev = 0; prev < 3; prev ++) {
			List<Cost> prevList = costList[prev];
			prevList.sort((o1, o2) -> o1.compareTo(o2));
			int nextLen = costList[prev + 1].size();
			for(int next = 0; next < nextLen; ++next) {
				int cost = Integer.MAX_VALUE;
				for(int p = 0; p < prevList.size(); ++p) {
					if(!hash[prev].get(prevList.get(p).idx).contains(next)) {
						cost = prevList.get(p).cost;
						break;
					}
				}
				if(cost == Integer.MAX_VALUE) costList[prev + 1].get(next).cost = Integer.MAX_VALUE;
				else costList[prev + 1].get(next).cost += cost;
			}
		}
		int ans = Integer.MAX_VALUE;
		for(int i = 0; i < costList[3].size(); ++i)
			ans = Math.min(ans, costList[3].get(i).cost);
		if(ans == Integer.MAX_VALUE) System.out.println(-1);
		else System.out.println(ans);
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