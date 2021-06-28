#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

template<typename T>
void print(const vector<vector<T>>& v, char sp=' ') {
	int n=v.size();
	if(n==0)
		return;
	int m=v[0].size();
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			if(j>0)
				cout << sp;
			cout << v[i][j];
		}
		cout << '\n';
	}
}

template<typename T>
void print(const vector<T>& v, char sp=' ') {
	for(int i=0; i<v.size(); ++i) {
		if(i>0)
			cout << sp;
		cout << v[i];
	}
	cout << '\n';
}

template<typename T>
void print(T v) {
	cout << v << '\n';
}

template<typename T>
void read(vector<vector<T>>& v) {
	for(auto& a : v)
		for(auto& i : a)
			cin >> i;
}

template<typename T>
void read(vector<T>& v) {
	for(auto& x : v)
		cin >> x;
}

const int mxN=10;
int a[mxN][mxN], tmp[mxN][mxN];
int ans;

const int dr[5]={-1, 1, 0, 0, 0};
const int dc[5]={0, 0, -1, 0, 1};

bool can(int r, int c) {
	return r>=0&&c>=0&&mxN>r&&mxN>c;
}

void push(int r, int c) {
	for(int i=0; i<5; ++i)
		if(can(r+dr[i], c+dc[i]))
			a[r+dr[i]][c+dc[i]]^=1;
}

bool chk() {
	for(int i=0; i<mxN; ++i) {
		for(int j=0; j<mxN; ++j) {
			if(a[i][j])
				return false;
		}
	}
	return true;
}

void copy() {
	for(int i=0; i<mxN; ++i)
		for(int j=0; j<mxN; ++j)
			a[i][j]=tmp[i][j];
}

void solve() {
	char c;
	ans=1e5;
	for(int i=0; i<mxN; ++i) {
		for(int j=0; j<mxN; ++j) {
			cin >> c;
			tmp[i][j]=a[i][j]=c=='O';
		}
	}
	for(int k=0; k<(1<<mxN); ++k) {
		copy();
		int cnt=0;
		for(int c=0; c<mxN; ++c) {
			if(k&(1<<c)) {
				push(0, c);
				++cnt;
			}
		}
		for(int r=1; r<mxN; ++r) {
			for(int c=0; c<mxN; ++c) {
				if(a[r-1][c]) {
					push(r, c);
					++cnt;
				}
			}
		}
		if(chk())
			ans=min(ans, cnt);
	}

	print(ans==1e5?-1:ans);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
