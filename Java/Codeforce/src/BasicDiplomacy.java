import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class BasicDiplomacy {
	static class Friend implements Comparable<Friend> {
		int id;
		int dayCount;
		Set<Integer> possibleDays;
		Friend(int id) {
			this.id = id;
			this.dayCount = 0;
			possibleDays = new HashSet<>();
		}
		void addPossibleDay(int day) {
			possibleDays.add(day);
		}
		//need?
		void participate(int day) {
			++dayCount;
			possibleDays.remove(day);
		}
		void increaseDayCount() {
			++dayCount;
		}
		public int compareTo(Friend f) {
			return Integer.compare(dayCount, f.dayCount);
		}
		boolean canPlayAtDay(int day) {
			return possibleDays.contains(day);
		}
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		for (int tc = 0; tc < testCase; tc++) {
			int nTotalFriend = fs.nextInt(), m = fs.nextInt();
			int limit = (int)Math.ceil((double)m / 2);
			Map<Integer, Friend> friends = new HashMap<>();
			for(int i = 1; i <= nTotalFriend; ++i) {
				friends.put(i, new Friend(i));
			}
			int[] ans = new int[m];
			Arrays.fill(ans, -1);
			int assignCount = 0;
			for(int day = 0; day < m; ++day) {
				int k = fs.nextInt();
				for(int i = 0; i < k; ++i) {
					int nFriend = fs.nextInt();
					Friend f = friends.get(nFriend);
					f.addPossibleDay(day);
					if(k == 1) {
						//we can only invite this friend to this day;
						if(f.dayCount >= limit) {
							continue;
						}
						f.participate(day);
						ans[day] = nFriend;
						++assignCount;
					}
				}
			}
			PriorityQueue<Friend> pq = new PriorityQueue<>();
			for(Friend f : friends.values()) {
				pq.add(f);
			}
			while(!pq.isEmpty() && pq.peek().dayCount < limit) {
				Friend f = pq.poll();
				for(int day : f.possibleDays) {
					if(f.dayCount >= limit) {
						break;
					}
					if(ans[day] != -1) {
						continue;
					}
					ans[day] = f.id;
					f.increaseDayCount();
					++assignCount;
				}
			}
			if(assignCount == m) {
				System.out.println("YES");
				for(int i = 0; i < m; ++i) {
					System.out.print(ans[i] + " ");
				}
				System.out.println();
			} else {
				System.out.println("NO");
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