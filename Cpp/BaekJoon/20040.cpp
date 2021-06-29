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

const int mxN=5e5;
int p[mxN];
int n, m;

int find(int a) {
	if(p[a]==a)
		return a;
	return p[a]=find(p[a]);
}

void merge(int a, int b) {
	p[find(a)]=find(b);
}

bool same(int a, int b) {
	return find(a)==find(b);
}

void solve() {
	cin >> n >> m;
	for(int i=0; i<n; ++i)
		p[i]=i;
	int ans=0;
	for(int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v;
		if(same(u, v)&&!ans)
			ans=i+1;
		merge(u, v);
	}
	print(ans);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
