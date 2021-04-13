import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class FencePainting {
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		outer : for (int tc = 0; tc < testCase; tc++) {
			int nPlank = fs.nextInt(), nPainter = fs.nextInt();
			int[] color = fs.readArray(nPlank);
			int[] target = fs.readArray(nPlank);
			int[] painterColor = fs.readArray(nPainter);
			HashMap<Integer, TreeSet<Integer>> mp = new HashMap<>();
			HashMap<Integer, Integer> same = new HashMap<>();
			for(int i = 0; i < nPlank; ++i) {
				if(color[i] == target[i]) {
					same.put(target[i], i + 1);
					continue;
				}
				if(!mp.containsKey(target[i]))
					mp.put(target[i], new TreeSet<>());
				mp.get(target[i]).add(i + 1);
			}
			int prev = -1;
			List<Integer> ansList = new ArrayList<>();
			for(int i = nPainter - 1; i >= 0; --i) {
				if(!mp.containsKey(painterColor[i])) {
					if(prev == -1) {
				        if(!same.containsKey(painterColor[i])) {
					        System.out.println("NO");
					        continue outer;
				        } else {
					        prev = same.get(painterColor[i]);
				        }
					}
				} else {
					TreeSet<Integer> indexes = mp.get(painterColor[i]);
					if(!indexes.isEmpty()) {
						prev = indexes.first();
						indexes.remove(prev);
					}
				}
				ansList.add(prev);
			}
			for(TreeSet<Integer> remain : mp.values())  {
				if(!remain.isEmpty()) {
					System.out.println("NO");
					continue outer;
				}
			}
			System.out.println("YES");
			for(int i = ansList.size() - 1; i >= 0; --i)
				System.out.print(ansList.get(i) + " ");
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