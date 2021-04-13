import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Berpizza {
	static class Customer {
		int id;
		int money;
		public Customer(int id, int money) {
			this.id = id;
			this.money = money;
		}
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int nQuery = fs.nextInt();
		TreeSet<Customer> monoSet = new TreeSet<>(Comparator.comparingInt(o -> o.id));
		TreeSet<Customer> polySet = new TreeSet<Customer>((o1, o2) -> {
			if(o1.money == o2.money) return Integer.compare(o2.id, o1.id);
			return Integer.compare(o1.money, o2.money);
		});
		int id = 1;
		for (int qq = 0; qq < nQuery; qq++) {
			int cmd = fs.nextInt();
			if(cmd == 1) {
				int m = fs.nextInt();
				Customer customer = new Customer(id++, m);
				monoSet.add(customer);
				polySet.add(customer);
			} else {
				Customer customer = null;
				if(cmd == 2) customer = monoSet.first();
				else customer = polySet.last();
				System.out.print(customer.id + " ");
				monoSet.remove(customer);
				polySet.remove(customer);
			}
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