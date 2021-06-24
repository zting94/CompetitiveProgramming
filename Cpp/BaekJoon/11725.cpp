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

const int mxN=1e5+1;
int p[mxN];
int n;
vector<int> adj[mxN];
bool vis[mxN];

void dfs(int u=1, int prev=-1) {
	if(vis[u])
		return;
	vis[u]=true;
	p[u]=prev;
	for(int v : adj[u]) {
		dfs(v, u);
	}
}

void solve() {
	cin >> n;
	for(int i=0; i<n-1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	for(int i=2; i<=n; ++i)
		cout << p[i] << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
