import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class P2042 {
	// node 번째 번호의 TreeNode 가 담당하는 구간이 [start, end] 임
	static long init(long[] tree, int node, int start, int end, long[] arr) {
		if(start == end)
			return tree[node] = arr[start];
		int mid = (start + end) / 2;
		return tree[node] = init(tree, node * 2, start, mid, arr) + init(tree, node * 2 + 1, mid + 1, end, arr);
	}
	static void update(long[] tree, int node, int start, int end, int targetNode, long val) {
		if(targetNode < start || end < targetNode)
			return;
		tree[node] += val;
		if(start != end) {
			int mid = (start + end) / 2;
			update(tree, node * 2, start, mid, targetNode, val);
			update(tree, node * 2 + 1, mid + 1, end, targetNode, val);
		}
	}
	static long getSum(long[] tree, int node, int start, int end, int left, int right) {
		if(right < start || end < left)
			return 0;
		if(left <= start && end <= right)
			return tree[node];
		int mid = (start + end) / 2;
		return getSum(tree, node * 2, start, mid, left, right) + getSum(tree, node * 2 + 1, mid + 1, end, left, right);
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out, true);
		int n = fs.nextInt(), m = fs.nextInt(), k = fs.nextInt();
		int v = (int)Math.ceil(Math.log(n)/ Math.log(2));
		long[] arr = new long[n + 1];
		long[] tree = new long[1 << v + 1];
		for(int i = 1; i <= n; ++i) {
			arr[i] = fs.nextLong();
		}
		init(tree, 1, 1, n, arr);
		for(int i = 0; i < m + k; ++i) {
			int a = fs.nextInt();
			if(a == 1) {
				int b = fs.nextInt();
				long c = fs.nextLong();
				long diff = c - arr[b];
				arr[b] = c;
				update(tree, 1, 1, n, b, diff);
			} else {
				int b = fs.nextInt(), c = fs.nextInt();
				System.out.println(getSum(tree, 1,1, n, b, c));
			}
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