import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class P1697 {
	static class State {
		int cnt;
		int coord;
		public State(int cnt, int coord) {
			this.cnt = cnt;
			this.coord = coord;
		}
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		int start = fs.nextInt(), target = fs.nextInt();
		Queue<State> q = new LinkedList();
		HashSet<Integer> h = new HashSet<>();
		q.add(new State(0, start));
		while(!q.isEmpty()) {
			State s = q.poll();
			if(s.coord == target) {
				System.out.println(s.cnt);
				break;
			}
			if(s.coord < 0 || 100000 < s.coord || h.contains(s.coord))
				continue;
			h.add(s.coord);
			q.add(new State(s.cnt + 1, s.coord * 2));
			q.add(new State(s.cnt + 1, s.coord + 1));
			q.add(new State(s.cnt + 1, s.coord - 1));
		}
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