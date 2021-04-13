import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class P1922Kruskal {
	static class Union {
		int[] parent;
		Union(int sz) {
			parent = new int[sz];
			for(int i = 0; i < sz; ++i) {
				parent[i] = i;
			}
		}
		int find(int a) {
			if(parent[a] == a) {
				return a;
			}
			return parent[a] = find(parent[a]);
		}
		void merge(int a, int b) {
		    int parentA = find(a);
		    int parentB = find(b);
		    parent[parentB] = parentA;
		}
		boolean isInSameUnion(int a, int b) {
		    int parentA = find(a);
		    int parentB = find(b);

		    return parentA == parentB;
		}
	}
    static class Edge implements Comparable<Edge> {
        int from;
        int to;
        int cost;
		public Edge(int from, int to, int cost) {
			this.from = from;
			this.to = to;
			this.cost = cost;
		}
		@Override
		public int compareTo(Edge o) {
		    return Integer.compare(this.cost, o.cost);
		}
	}
	//Kruskal's Algorithm
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out, true);
		int n = fs.nextInt();
		int nConnect = fs.nextInt();
		PriorityQueue<Edge> pq = new PriorityQueue<>();
		Union union = new Union(n);
		for(int i = 0; i < nConnect; ++i) {
		    int from = fs.nextInt() - 1, to = fs.nextInt() - 1, cost = fs.nextInt();
		    pq.add(new Edge(from, to, cost));
		    pq.add(new Edge(to, from, cost));
		}
		int totalCost = 0;
		while(!pq.isEmpty()) {
		    Edge e = pq.poll();
		    if(union.isInSameUnion(e.from, e.to)) {
		        continue;
			}
		    totalCost += e.cost;
		    union.merge(e.from, e.to);
		}
		out.println(totalCost);
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