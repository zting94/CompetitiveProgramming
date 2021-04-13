import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class P2357 {
	static int minInit(int[] tree, int node, int start, int end, int[] arr) {
		if(start == end)
			return tree[node] = arr[start];
		int mid = (start + end) / 2;
		return tree[node] = Math.min(minInit(tree, node * 2, start, mid, arr), minInit(tree, node * 2 + 1, mid + 1, end, arr));
	}
	static int maxInit(int[] tree, int node, int start, int end, int[] arr) {
		if(start == end)
			return tree[node] = arr[start];
		int mid = (start + end) / 2;
		return tree[node] = Math.max(maxInit(tree, node * 2, start, mid, arr), maxInit(tree, node * 2 + 1, mid + 1, end, arr));
	}
	static int getMin(int[] tree, int node, int start, int end, int left, int right) {
		if(end < left || right < start)
			return Integer.MAX_VALUE;
		if(left <= start && end <= right)
			return tree[node];
		int mid = (start + end) / 2;
		return Math.min(getMin(tree, node * 2, start ,mid, left, right), getMin(tree, node * 2 + 1, mid + 1, end, left, right));
	}
	static int getMax(int[] tree, int node, int start, int end, int left, int right) {
		if(end < left || right < start)
			return Integer.MIN_VALUE;
		if(left <= start && end <= right)
			return tree[node];
		int mid = (start + end) / 2;
		return Math.max(getMax(tree, node * 2, start, mid, left, right), getMax(tree, node * 2 + 1, mid + 1, end, left, right));
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out, true);
		int n = fs.nextInt(), m = fs.nextInt();
		int shift = (int)Math.ceil(Math.log(n) / Math.log(2));
		int[] arr = new int[n + 1];
		int[] maxTree = new int[1 << shift + 1];
		int[] minTree = new int[1 << shift + 1];
		for(int i = 1; i <= n; ++i)
			arr[i] = fs.nextInt();
		minInit(minTree, 1, 1, n, arr);
		maxInit(maxTree, 1, 1, n, arr);
		for(int i = 0; i < m; ++i) {
			int left = fs.nextInt(), right = fs.nextInt();
			System.out.println(getMin(minTree, 1, 1, n, left, right) + " " + getMax(maxTree, 1, 1, n, left, right));
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