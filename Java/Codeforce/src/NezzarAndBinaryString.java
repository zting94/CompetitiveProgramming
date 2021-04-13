import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class NezzarAndBinaryString {
	static int countOne(char[] arr, int l, int r) {
		int cnt = 0;
		for (int i = l; i <= r; i++) {
			if(arr[i] == '1')
				++cnt;
		}
		return cnt;
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
			for(int qq = 0; qq < nQ; ++qq) {
				left[qq] = fs.nextInt();
				right[qq] = fs.nextInt();
			}
			for(int i = nQ - 1; i >= 0; --i) {
				int l = left[i];
				int r = right[i];
				int len = r - l + 1;
				int half = (len + 1) / 2;
				int oneCount = countOne(current, l - 1, r - 1);
				/*
				System.out.println("left : " + l +
						"\tright : " + r +
						"\thalf : " + half +
						"\tlen" + len +
						"\toneCount" + oneCount);
				 */
				if(len % 2 == 0 && oneCount == half) {
					out.println("NO");
					continue outer;
				}
				char changeChar = '0';
				if(oneCount >= half)
					changeChar = '1';
				for (int k = l - 1; k < r; k++)
					current[k] = changeChar;
				/*
				System.out.println("char : " + changeChar + "\t");
				for(char c : current)
					System.out.print(c + " ");
				System.out.println();
				 */
			}
			for(int i = 0; i < n; ++i) {
				if(target[i] != current[i]) {
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