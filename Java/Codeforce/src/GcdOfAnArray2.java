import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class GcdOfAnArray2 {
	static final int MOD = 1000000007;
    static List<Integer> primeList = new ArrayList<>();
    static Map<Integer, TreeSet<Integer>> primes = new HashMap<>();
    static int ans = 1;
    static void fillPrime() {
        primeList.add(2);
		outer : for(int i = 3; i <= (int)Math.sqrt(2 * 100000); ++i) {
			for(int j = 2; j <= (int)Math.sqrt(i); ++j) {
				if (i % j == 0)
					continue outer;
			}
			primeList.add(i);
		}
	}
	static int myPow(int base, int power) {
        int v = 1;
		for (int i = 0; i < power; i++) {
		    v *= base;
		    v %= MOD;
		}
		return v;
	}
	static void add(int value) {
        for(int prime : primeList) {
        	if(value == 1 || prime > value)
        		break;
        	int cnt = 0;
        	while(value % prime == 0) {
        		value /= prime;
        		++cnt;
			}
        	if(cnt == 0)
        	    continue;
        	if(!primes.containsKey(prime))
        		primes.put(prime, new TreeSet<>());
        	TreeSet<Integer> s = primes.get(prime);
		}
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		fillPrime();
		int n = fs.nextInt(), nQ = fs.nextInt();
		for(int i = 0; i < n; ++i) {
		    int v = fs.nextInt();
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