import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class TheRobot {
    static class Point {
    	int x;
    	int y;
    	Point(int x, int y) {
    		this.x = x;
    		this.y = y;
		}
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int testCase = fs.nextInt();
		outer : for (int tc = 0; tc < testCase; tc++) {
			char[] ch = fs.next().toCharArray();
			Point[] points = new Point[ch.length];
			int x = 0, y = 0;
			for(int i = 0; i < ch.length; ++i) {
				char c = ch[i];
			    if(c == 'R') ++x;
			    else if(c == 'L') --x;
			    else if(c == 'U') ++y;
			    else if(c == 'D') --y;
			    points[i] = new Point(x, y);
			}
			for(int i = 0; i < ch.length; ++i) {
				int curX = 0, curY = 0;
				Point p = points[i];
				for(char c : ch) {
					if((curX + 1 != p.x || curY != p.y) && c == 'R') ++curX;
					else if((curX - 1 != p.x || curY != p.y) && c == 'L') --curX;
					else if((curX != p.x || curY + 1 != p.y) && c == 'U') ++curY;
					else if((curX != p.x || curY - 1 != p.y) && c == 'D') --curY;
					/*
				    if(curX + 1 == p.x && curY == p.y && c == 'R') continue;
					else if(curX - 1 == p.x && curY == p.y && c == 'L') continue;
					else if(curX == p.x && curY + 1 == p.y && c == 'U') continue;
					else if(curX == p.x && curY - 1 == p.y && c == 'D') continue;
					else if(c == 'R') ++curX;
					else if(c == 'L') --curX;
					else if(c == 'U') ++curY;
					else if(c == 'D') --curY;
					 */
				}
				if(curX == 0 && curY == 0) {
					System.out.println(p.x + " " + p.y);
					continue outer;
				}
			}

			System.out.println("0 0");
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