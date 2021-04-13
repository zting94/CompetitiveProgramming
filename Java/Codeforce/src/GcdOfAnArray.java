import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class GcdOfAnArray {
	static final int MOD = 1000000007;
	static int lastPrime = 2;
    static List<Integer> primeList = new ArrayList<>();
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
	static class SegmentTree {
        SegmentTree leftChild, rightChild;
        int left, right;
        HashMap<Integer, Integer> primeHash;
        SegmentTree(int left, int right) {
            this.left = left;
            this.right = right;
            primeHash = new HashMap<>();
            for(int p : primeList)
                primeHash.put(p, 0);
            if(left != right) {
            	int mid = (left + right) / 2;
                leftChild = new SegmentTree(left, mid);
                rightChild = new SegmentTree(mid + 1, right);
			}
		}
		void updateValue(int l, int r, int val) {
        	if(right < l || r < left)
        		return;
        	if(l <= left && right <= r) {
				for (int p : primeList) {
					if (val < p)
						break;
					int cnt = 0;
					while(val % p == 0) {
						++cnt;
						val /= p;
					}
					if(cnt == 0)
						continue;
					lastPrime = Math.max(lastPrime, p);
					//System.out.println("PUT : " + p + "CNT : " + cnt);
					primeHash.put(p, primeHash.get(p) + cnt);
				}
				return;
			}
        	leftChild.updateValue(l, r, val);
        	rightChild.updateValue(l, r, val);
		}
		int getValue(int l, int r, int val) {
            if(right < l || r < left)
            	return Integer.MAX_VALUE;
            if(leftChild == null || rightChild == null)
				return primeHash.get(val);
            return Math.min(leftChild.getValue(l, r, val), rightChild.getValue(l, r, val));
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
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		fillPrime();
		int n = fs.nextInt(), nQ = fs.nextInt();
		SegmentTree segmentTree = new SegmentTree(1, n);
		for(int i = 1; i <= n; ++i)
			segmentTree.updateValue(i, i, fs.nextInt());
		for (int q = 0; q < nQ; q++) {
			int idx = fs.nextInt(), val = fs.nextInt();
			segmentTree.updateValue(idx, idx, val);
			long ans = 1;
			for(int p : primeList) {
				if(p > lastPrime)
					break;
				int v = segmentTree.getValue(1, n, p);
				if(v == 0)
					continue;
				//System.out.println("p : " + p + "\tv : " + v);
				ans *= myPow(p, v);
				ans %= MOD;
			}
			System.out.println(ans);
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