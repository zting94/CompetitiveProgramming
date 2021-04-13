import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Playlist {
	static int getGcd(Map<Integer, Map<Integer, Integer>> gcds, int a, int b) {
		if(gcds.containsKey(a)) {
			if(gcds.get(a).containsKey(b)) {
				return gcds.get(a).get(b);
			}
		}
		if(b == 0) {
			if(!gcds.containsKey(a)) {
				gcds.put(a, new HashMap<Integer, Integer>());
			}
			if(!gcds.get(a).containsKey(b)) {
				gcds.get(a).put(b, a);
			}
			return a;
		}
		return getGcd(gcds, b, a % b);
	}
	static class Song {
		int genre;
		int index;
		Song(int genre, int index) {
			this.genre = genre;
			this.index = index;
		}
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		for (int tc = 0; tc < testCase; tc++) {
			int n = fs.nextInt();
			List<Song> list = new LinkedList<>();
			Map<Integer, Map<Integer, Integer>> gcds = new HashMap<>();
			for(int i = 0; i < n; ++i) {
				list.add(new Song(fs.nextInt(), i + 1));
			}
			while(true) {
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