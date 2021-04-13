import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class NezzarAndBinaryStringLazy {
	static class SegmentTree {
		SegmentTree leftChild;
		SegmentTree rightChild;
		int left;
		int right;
		int sum;
		int updateVal;
		SegmentTree(int l, int r) {
			sum = 0;
			updateVal = -1;
			this.left = l;
			this.right = r;
			if(l != r) {
				int mid = (l + r) / 2;
				leftChild = new SegmentTree(l, mid);
				rightChild = new SegmentTree(mid + 1, r);
			}
		}
		boolean needUpdate() {
			return updateVal != -1;
		}
		int getSum() {
			if(!needUpdate())
				return sum;
			return updateVal == 0 ? 0 : (right - left + 1);
		}
		void update() {
			if(left == right)
				return;
			sum = leftChild.getSum() + rightChild.getSum();
		}
		void propagate() {
			if(!needUpdate())
				return;
			if(left == right) {
				sum = updateVal;
				updateVal = -1;
				return;
			}
			leftChild.updateVal = updateVal;
			rightChild.updateVal = updateVal;
			updateVal = -1;
			update();
		}
		void setValue(int l, int r, int value) {
			propagate();
			if(right < l || r < left)
				return;
			if(l <= left && right <= r) {
				updateVal = value;
				return;
			}
			leftChild.setValue(l, r, value);
			rightChild.setValue(l, r, value);
			update();
		}
		int getRangeSum(int l, int r) {
			propagate();
			if(r < left || right < l)
				return 0;
			if(l <= left && right <= r)
				return getSum();
			return leftChild.getRangeSum(l, r) + rightChild.getRangeSum(l, r);
		}
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		outer : for (int tc = 0; tc < testCase; tc++) {
			int n = fs.nextInt(), nQ = fs.nextInt();
			char[] target = fs.next().toCharArray();
			char[] current = fs.next().toCharArray();
			int[] left = new int[nQ];
			int[] right = new int[nQ];
			SegmentTree segmentTree = new SegmentTree(1, n);
			for(int i = 1; i <= n; ++i)
				segmentTree.setValue(i, i, current[i - 1] - '0');
			for(int qq = 0; qq < nQ; ++qq) {
				left[qq] = fs.nextInt();
				right[qq] = fs.nextInt();
			}
			for(int i = nQ - 1; i >= 0; --i) {
				int l = left[i];
				int r = right[i];
				int len = r - l + 1;
				int half = (len + 1) / 2;
				int oneCount = segmentTree.getRangeSum(l, r);
				if(len % 2 == 0 && oneCount == half) {
					out.println("NO");
					continue outer;
				}

				/*
				System.out.println("left : " + l +
						"\tright : " + r +
						"\thalf : " + half +
						"\tlen" + len +
						"\toneCount" + oneCount);
				 */

				if(oneCount >= half)
					segmentTree.setValue(l, r, 1);
				else
					segmentTree.setValue(l, r, 0);
			}
			for(int i = 1; i <= n; ++i) {
				//System.out.println("i : " + i + "\tsum : " + segmentTree.getRangeSum(i, i));
				if(target[i - 1] - '0' != segmentTree.getRangeSum(i, i)) {
					out.println("NO");
					continue outer;
				}
			}
			out.println("YES");
			/*
			for(char c : current)
				System.out.print(c + " ");
			System.out.println("\n=======================================");
			 */
		}
		out.close();
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