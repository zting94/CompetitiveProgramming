#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

template<typename T>
void print(const vector<T>& v, char sp=' ') {
	for(int i=0; i<v.size(); ++i) {
		if(i>0)
			cout << sp;
		cout << v[i];
	}
	cout << '\n';
}

void print(int v) {
	cout << v << '\n';
}

template<typename T>
void read(vector<T>& v) {
	for(auto& x : v)
		cin >> x;
}

const int mxN=101;
const int mxD=1e5;
int n, m, r;
vector<int> adj[mxN];
int d[mxN][mxN];
int c[mxN];

void solve() {
	cin >> n >> m >> r;
	for(int i=0; i<n; ++i) 
		cin >> c[i];
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			d[i][j]=(i==j?0:mxD);
	for(int i=0; i<r; ++i) {
		int u, v, l;
		cin >> u >> v >> l, --u, --v;
		d[u][v]=d[v][u]=l;
	}
	for(int k=0; k<n; ++k) 
		for(int i=0; i<n; ++i) 
			for(int j=0; j<n; ++j) 
				if(d[i][k]+d[k][j]<d[i][j])
					d[i][j]=d[i][k]+d[k][j];
	int ans=0;
	for(int i=0; i<n; ++i) {
		int cur=0;
		for(int j=0; j<n; ++j) {
			if(d[i][j]<=m)
				cur+=c[j];
		}
		ans=max(ans, cur);
	}
	print(ans);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
