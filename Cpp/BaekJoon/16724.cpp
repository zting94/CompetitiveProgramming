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

const int mxN=1e3;
int N, M;
char a[mxN][mxN];
bool v[mxN][mxN];

bool can(int r, int c) {
	return r>=0&&c>=0&&N>r&&M>c;
}

void dfs(int i, int j) {
	if(!can(i, j)||v[i][j])
		return;
	v[i][j]=true;
	if(a[i][j]=='D')
		dfs(i+1, j);
	else if(a[i][j]=='L')
		dfs(i, j-1);
	else if(a[i][j]=='R')
		dfs(i, j+1);
	else
		dfs(i-1, j);
	if(can(i+1, j)&&!v[i+1][j]&&a[i+1][j]=='U')
		dfs(i+1, j);
	if(can(i-1, j)&&!v[i-1][j]&&a[i-1][j]=='D')
		dfs(i-1, j);
	if(can(i, j-1)&&!v[i][j-1]&&a[i][j-1]=='R')
		dfs(i, j-1);
	if(can(i, j+1)&&!v[i][j+1]&&a[i][j+1]=='L')
		dfs(i, j+1);
}

void solve() {
	cin >> N >> M;
	for(int i=0; i<N; ++i) 
		for(int j=0; j<M; ++j) {
			cin >> a[i][j];
			v[i][j]=false;
		}
	int ans=0;
	for(int i=0; i<N; ++i) {
		for(int j=0; j<M; ++j) {
			if(!v[i][j]) {
				++ans;
				dfs(i, j);
			}
		}
	}
	print(ans);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
