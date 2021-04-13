import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class CardDeck {
	static class Card implements Comparable<Card> {
		int value;
		int index;
		Card(int value, int index) {
			this.value = value;
			this.index = index;
		}
		public int compareTo(Card c) {
			return Integer.compare(this.value, c.value);
		}
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		for (int tc = 0; tc < testCase; tc++) {
			int n = fs.nextInt();
			Card[] cardList = new Card[n];
			int[] arr = new int[n];
			for(int i = 0; i < n; ++i) {
				arr[i] = fs.nextInt();
				cardList[i] = new Card(arr[i], i);
			}
			Arrays.sort(cardList, Collections.reverseOrder());
			boolean[] processed = new boolean[n];
			for(int i = 0; i < n; ++i) {
				for(int j = cardList[i].index; j < n; ++j) {
					if(processed[j]) {
						break;
					}
					processed[j] = true;
					System.out.print(arr[j] + " ");
				}
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