#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int mxN=1e3;
int n, m;
vector<int> adj[mxN];
bool v1[mxN], v2[mxN];

void dfs(int u) {
	if(v1[u]) {
		return;
	}
	cout << u+1 << ' ';
	v1[u]=true;
	for(int next : adj[u]) {
		dfs(next);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		if(v2[u]) {
			continue;
		}
		v2[u]=true;
		cout << u+1 << ' ';
		for(int next : adj[u]) {
			q.push(next);
		}
	}
}

void solve() {
	int u;
	cin >> n >> m >> u;
	for(int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0; i<n; ++i) {
		sort(adj[i].begin(), adj[i].end());
	}
	dfs(u-1);
	cout << '\n';
	bfs(u-1);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
