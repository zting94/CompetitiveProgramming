import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

//TODO: rename to Main
public class P2252 {
	static class Student {
		int id;
		int numPrevStudent;
		boolean placed;
		List<Integer> nextStudentIdList;
		Student(int id) {
			this.id = id;
			numPrevStudent = 0;
			nextStudentIdList = new ArrayList<>();
			placed = false;
		}
		void addNextStudent(int nextStudentId) {
			nextStudentIdList.add(nextStudentId);
		}
		void prevStudentStood() {
			--numPrevStudent;
		}
		void increaseNeededPrevStudentCount() {
			++numPrevStudent;
		}
		boolean canStand() {
			return numPrevStudent == 0;
		}
		boolean isPlaced() {
			return placed;
		}
	}
	public static void main(String[] args)  {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out, true);
		int n = fs.nextInt();
		int m = fs.nextInt();
		Student[] students = new Student[n];
		for (int i = 0; i < n; ++i) {
			students[i] = new Student(i);
		}
		for (int i = 0; i < m; ++i) {
			int prev = fs.nextInt() - 1, next = fs.nextInt() - 1;
			Student prevStudent = students[prev];
			Student nextStudent = students[next];
			prevStudent.addNextStudent(nextStudent.id);
			nextStudent.increaseNeededPrevStudentCount();
		}
		Queue<Student> q = new LinkedList<>();
		for (int i = 0; i < n; ++i) {
			if (students[i].canStand()) {
				q.add(students[i]);
			}
		}
		while (!q.isEmpty()) {
			Student student = q.poll();
			out.print(student.id + 1 + " ");
			for (int nextId : student.nextStudentIdList) {
				students[nextId].prevStudentStood();
				if (students[nextId].canStand()) {
					q.add(students[nextId]);
				}
			}
		}
		out.println();
		out.close();
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