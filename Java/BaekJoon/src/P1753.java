import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

//TODO: rename to Main
//TLE
public class P1753 {
	static class Pair implements Comparable<Pair> {
	    int to;
	    int cost;

		public Pair(int to, int cost) {
			this.to = to;
			this.cost = cost;
		}

		@Override
		public int compareTo(Pair o) {
		    return Integer.compare(this.cost, o.cost);
		}
	}

	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out, true);
		int nVertex = fs.nextInt(), nEdge = fs.nextInt();
		int start = fs.nextInt() - 1;
		List<Pair>[] edges = new ArrayList[nVertex];
		int[] costs = new int[nVertex];
		Arrays.fill(costs, (int)1e9);
		for (int i = 0; i < nVertex; ++i) {
			edges[i] = new ArrayList<>();
		}
		for (int i = 0; i < nEdge; ++i) {
			int from = fs.nextInt() - 1;
			int to = fs.nextInt() - 1;
			int cost = fs.nextInt();
			edges[from].add(new Pair(to, cost));
		}
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		pq.add(new Pair(start, 0));
		costs[start] = 0;
		while(!pq.isEmpty()) {
		    Pair from = pq.poll();
			if(costs[from.to] < from.cost) {
				continue;
			}
		    for(Pair pair : edges[from.to]) {
		        if(costs[from.to] + pair.cost < costs[pair.to]) {
		        	costs[pair.to] = costs[from.to] + pair.cost;
                    pq.add(new Pair(pair.to, costs[pair.to]));
				}
			}
		}
		for(int i = 0; i < nVertex; ++i) {
			if(costs[i] == (int)1e9) {
				out.println("INF");
			} else {
			    out.println(costs[i]);
			}
		}
		out.flush();
		out.close();
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