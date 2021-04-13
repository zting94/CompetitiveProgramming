import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class DivideAndSummarize {
    static class SegmentTree {
        SegmentTree leftChild, rightChild;
        int left, right;
        int value;
        int maxValue, minValue;
        SegmentTree(int left, int right) {
        	this.left = left;
        	this.right = right;
        	this.value = -1;
        	this.maxValue = Integer.MIN_VALUE;
        	this.minValue = Integer.MAX_VALUE;
        	if(left != right) {
        		int mid = (left + right) / 2;
        		leftChild = new SegmentTree(left, mid);
        		rightChild = new SegmentTree(mid + 1, right);
			}
		}
		int getMin(int l, int r) {
            if(right < l || r < left)
            	return Integer.MAX_VALUE;
            if(l <= left && right <= r)
            	return this.minValue;
            return Math.min(leftChild.getMin(l, r), rightChild.getMin(l, r));
		}
		int getMax(int l, int r) {
        	if(right < l || r < left)
					return Integer.MIN_VALUE;
        	if(l <= left && right <= r)
        		return this.maxValue;
        	return Math.max(leftChild.getMax(l, r), rightChild.getMax(l, r));
		}
		void setValue(int l, int r, int val) {
            if(right < 1 || r < left)
            	return;
            if(l <= left && right <= r) {
				value = val;
				return;
			}
            int mid = (l + r) / 2;
            leftChild.setValue(l, r, val);
            rightChild.setValue(l, r, val);
		}
		void update(int l, int r) {
        	if(right < l || r < left)
        		return;
        	if(l == r) {
        		maxValue = minValue = value;
        		return;
			}
        	int mid = (l + r) / 2;
        	leftChild.update(l, mid);
        	rightChild.update(mid + 1, right);
        	maxValue = Math.max(leftChild.maxValue, rightChild.maxValue);
        	minValue = Math.min(leftChild.minValue, rightChild.minValue);
		}
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		for (int tc = 0; tc < testCase; tc++) {
			int n = fs.nextInt(), nQ = fs.nextInt();
			int[] arr = fs.readArray(n);
			ruffleSort(arr);
			SegmentTree segmentTree = new SegmentTree(1, n);
			for(int i = 1; i <= n; ++i)
				segmentTree.setValue(i, i, arr[i - 1]);
			segmentTree.update(1, n);
			int[] prefix = new int[n + 1];
			for(int i = 1; i <= n; ++i)
				prefix[i] = prefix[i - 1] + arr[i - 1];
			for (int q = 0; q < nQ; q++) {
			}
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