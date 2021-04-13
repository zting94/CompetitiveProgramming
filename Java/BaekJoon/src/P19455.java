import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class P19455 {
	/*
	static class Data {
		int minValue;
		int lazyValue;
		boolean needUpdate;
		boolean firstOR;
		public Data() {
			minValue = Integer.MAX_VALUE;
			lazyValue = 0;
			needUpdate = false;
			firstOR = false;
		}
	}
	static int init(Data[] tree, int nodeIdx, int start, int end, int[] arr) {
		if(start == end)
			return tree[nodeIdx].minValue = arr[start];
		int mid = (start + end) / 2;
		int l = init(tree, nodeIdx * 2, start, mid, arr);
		int r = init(tree, nodeIdx * 2 + 1, mid + 1, end, arr);
		return tree[nodeIdx].minValue = Math.min(l, r);
	}
	static int query(Data[] tree, int nodeIdx, int start, int end, int left, int right) {
		if(end < left || right < start)
			return Integer.MAX_VALUE;
		if(left <= start && right <= end) {
			if(!tree[nodeIdx].needUpdate)
				return tree[nodeIdx].minValue;
			return lazyUpdate(tree, nodeIdx, start, end, left, right);
		}
		int mid = (start + end) / 2;
		int l = query(tree, nodeIdx * 2, start, mid, left, right);
		int r = query(tree, nodeIdx * 2 + 1, mid + 1, end, left, right);
		return Math.min(l, r);
	}
	static int lazyUpdate(Data[] tree, int nodeIdx, int start, int end, int left, int right) {
		if(end < left || right < start)
			return Integer.MAX_VALUE;
		if(left <= start && right <= end) {
			Data t = tree[nodeIdx];
			if(!t.needUpdate)
				return t.minValue;
			if(t.firstOR) {
				t.minValue |= t.lazyValue;
			} else {
				t.minValue &= t.lazyValue;
			}
			t.needUpdate = false;
			t.firstOR = false;
			t.lazyValue = 0;
			return t.minValue;
		}
		int mid = (start + end) / 2;
		int l = lazyUpdate(tree, nodeIdx * 2, start, mid, left, right);
		int r = lazyUpdate(tree, nodeIdx * 2 + 1, mid + 1, end, left, right);
		Data t = tree[nodeIdx];
		t.needUpdate = false;
		t.firstOR = false;
		t.lazyValue = 0;
		return t.minValue = Math.min(l, r);
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out, true);
		int n = fs.nextInt();
		int treeSize = (int)Math.ceil(Math.log(n) / Math.log(2));
		int[] arr = fs.readArray(n);
		Data[] tree = new Data[1 << treeSize + 1];
		init(tree, 1, 0, n - 1, arr);
		int m = fs.nextInt();
		for(int i = 0; i < m; ++i) {
		}
	}
	 */
	public static void main(String[] args) {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out, true);
		int n = fs.nextInt();
		int treeSize = (int)Math.ceil(Math.log(n) / Math.log(2));
		int[] arr = fs.readArray(n);
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