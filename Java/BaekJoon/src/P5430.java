import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class P5430 {
	static class Helper {
		Deque<Integer> dq;
		int direction;
		Helper() {
			dq = new ArrayDeque<>();
			direction = 0;
		}
		void push(int v) {
			dq.addLast(v);
		}
		boolean delete() {
			if(dq.isEmpty()) return false;
			if(direction == 0) dq.removeFirst();
			else dq.removeLast();
			return true;
		}
		void reverse() {
			direction = 1 - direction;
		}
		void print() {
			if(direction == 0) printBackward();
			else printForward();
		}
		void printBackward() {
			System.out.print("[");
			while(1 < dq.size())
				System.out.print(dq.removeFirst() + ",");
			if(!dq.isEmpty())
				System.out.print(dq.removeFirst());
			System.out.println("]");
		}
		void printForward() {
			System.out.print("[");
			while(1 < dq.size())
				System.out.print(dq.removeLast() + ",");
			if(!dq.isEmpty())
				System.out.print(dq.removeLast());
			System.out.println("]");
		}
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out, true);
		int tc = fs.nextInt();
		outer : for(int t = 0; t < tc; ++t) {
			String cmd = fs.next();
			int n = fs.nextInt();
			String line = fs.next();
			String[] list = line.substring(1, line.length() - 1).split(",");
			Helper h = new Helper();
			for(String s : list) {
				if(!s.isEmpty())
					h.push(Integer.parseInt(s));
			}
			for(char c : cmd.toCharArray()) {
				if(c == 'R') {
					h.reverse();
				} else {
					if(!h.delete()) {
						System.out.println("error");
						continue outer;
					}
				}
			}
			h.print();
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