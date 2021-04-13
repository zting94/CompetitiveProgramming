import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class TheGreatHero {
	static class Monster implements Comparable<Monster>  {
		int attack;
		int hp;
		public int compareTo(Monster o) {
			return attack - o.attack;
		}
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		for (int tc = 0; tc < testCase; tc++) {
			long heroAttack = fs.nextLong(), heroHP = fs.nextLong();
			int nMonster = fs.nextInt();
			Monster[] monster = new Monster[nMonster];
			for(int i = 0; i < nMonster; ++i) {
				monster[i] = new Monster();
				monster[i].attack = fs.nextInt();
			}
			for(int i = 0; i < nMonster; ++i)
				monster[i].hp = fs.nextInt();
			Arrays.sort(monster);
			for(int i = 0; i < nMonster; ++i) {
				Monster m = monster[i];
				long heroAttackCount = (long)Math.ceil((double)m.hp / heroAttack);
				heroHP -= m.attack * heroAttackCount;
			}
			heroHP += monster[nMonster - 1].attack;
			if(heroHP > 0) System.out.println("YES");
			else System.out.println("NO");
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