import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class P1922Prim {
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
		public int compareTo(Edge e) {
		    return Integer.compare(this.cost, e.cost);
		}
	}
	//Prim's Algorithm
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out, true);
		int n = fs.nextInt();
		int nConnect = fs.nextInt();
		List<Edge>[] adjList = new ArrayList[n];
		for(int i = 0; i < n; ++i) {
			adjList[i] = new ArrayList<>();
		}
		for(int i = 0; i < nConnect; ++i) {
			int from = fs.nextInt() - 1;
			int to = fs.nextInt() - 1;
			int cost = fs.nextInt();
			adjList[from].add(new Edge(from, to, cost));
			adjList[to].add(new Edge(to, from, cost));
		}
		PriorityQueue<Edge> pq = new PriorityQueue<>();
		boolean[] added = new boolean[n];
		int totalCost = 0;
		int addedCount = 1;
		added[0] = true;
		pq.addAll(adjList[0]);
		while(!pq.isEmpty() && addedCount < n) {
			Edge e = pq.poll();
			if(added[e.to]) {
				continue;
			}
			totalCost += e.cost;
			added[e.to] = true;
			for(Edge nextEdge : adjList[e.to]) {
			    if(!added[nextEdge.to]) {
			    	pq.add(nextEdge);
				}
			}
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