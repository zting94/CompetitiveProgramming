import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

//TODO: rename to Main
public class P10999 {
	static class SegmentTree {
	    int left, right;
	    long sum;
	    long value;
	    long updateVal;
		SegmentTree leftChild, rightChild;
	    SegmentTree(int left, int right, long[] arr) {
	        this.left = left;
	        this.right = right;
	        updateVal = 0;
	        leftChild = rightChild = null;
	        if(left == right) {
	        	sum = value = arr[left - 1];
	        	return;
			}
	        int mid = (left + right) / 2;
	        leftChild = new SegmentTree(left, mid, arr);
	        rightChild = new SegmentTree(mid + 1, right, arr);
	        sum = leftChild.sum + rightChild.sum;
		}
		void print() {
	    	if(left == right) {
				System.out.println("idx : " + left + "\tsum : " + sum);
			} else {
				System.out.println("l : " + left + "\tr : " + right + "\tsum : " + sum);
	    		leftChild.print();
	    		rightChild.print();
			}
		}
		void propagate() {
	        sum += (right - left + 1) * updateVal;
	        if(left != right) {
	        	leftChild.updateVal += updateVal;
	        	rightChild.updateVal += updateVal;
			}

	        updateVal = 0;
		}
		long query(int l, int r) {
	    	propagate();
	        if(r < left || right < l) {
	        	return 0L;
			}
	        if(l <= left && right <= r) {
	            return sum;
			}
	        return leftChild.query(l, r) + rightChild.query(l, r);
		}
		void updateRangeValue(int l, int r, long val) {
	        propagate();
	        if(r < left || right < l) {
	        	return;
			}
	        if(l <= left && right <= r) {
	            sum += (right - left + 1) * val;
	            if(left != right) {
	            	leftChild.updateVal += val;
	            	rightChild.updateVal += val;
				}
			} else {
	            leftChild.updateRangeValue(l, r, val);
	            rightChild.updateRangeValue(l, r, val);
	            sum = leftChild.sum + rightChild.sum;
			}
		}
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out, true);
		int n = fs.nextInt();
		int nUpdate = fs.nextInt();
		int nQuery = fs.nextInt() + nUpdate;
		long[] arr = fs.readLongArray(n);SegmentTree root = new SegmentTree(1, n, arr);
		for(int i = 0; i < nQuery; ++i) {
			int cmd = fs.nextInt();
			int l = fs.nextInt(), r = fs.nextInt();
			if(cmd == 1) {
			    long val = fs.nextLong();
			    root.updateRangeValue(l, r, val);
			} else {
				//System.out.println("before");
				//root.print();
				out.println(root.query(l, r));
				//System.out.println("after");
				//root.print();
			}
		}
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
		long[] readLongArray(int n) {
			long[] a = new long[n];
			for(int i = 0; i < n; ++i)
				a[i] = nextLong();
			return a;
		}
	}
}