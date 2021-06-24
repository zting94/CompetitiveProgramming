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
const int mxD=1e8;
vector<pair<int, int>> adj[mxN];
int d[mxN][mxN];
int n, m;

void solve() {
	cin >> n >> m;
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			d[i][j]=mxD;
	for(int i=0; i<m; ++i) {
		int u, v, w;
		cin >> u >> v >> w, --u, --v;
		d[u][v]=min(d[u][v], w);
	}
	for(int k=0; k<n; ++k) {
		for(int i=0; i<n; ++i) {
			for(int j=0; j<n; ++j) {
				if(d[i][k]+d[k][j]<d[i][j])
					d[i][j]=d[i][k]+d[k][j];
			}
		}
	}
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			if(i==j) {
				cout << "0 ";
			} else {
				cout << (d[i][j]>=mxD?0:d[i][j]) << ' ';
			}
		}
		cout << '\n';
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
