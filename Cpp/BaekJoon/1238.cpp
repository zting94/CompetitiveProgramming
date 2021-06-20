#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int mxN=1e4;
const int mx=1e8;
int n, m, x;

vector<int> dijkstra(const vector<vector<int>>& g, const vector<vector<int>>& adj, int n, int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dist(n, mx);
	pq.push({0, x});
	while(!pq.empty()) {
		auto [d, u]=pq.top();
		pq.pop();
		if(d>dist[u])
			continue;
		dist[u]=d;
		for(auto next : adj[u]) {
			//if(dist[next]==mx) {
			if(d+g[u][next]<dist[next]) {
				pq.push({d+g[u][next], next});
			}
		}
	}
	return dist;
}

void solve() {
	cin >> n >> m >> x, --x;
	vector<vector<int>> adj(n), adj_rev(n);
	vector<vector<int>> g(n, vector<int>(n, mx));
	vector<vector<int>> g_rev(n, vector<int>(n, mx));
	for(int i=0; i<m; ++i) {
		int u, v, t;
		cin >> u >> v >> t, --u, --v;
		adj[u].push_back(v);
		adj_rev[v].push_back(u);
		g[u][v]=g_rev[v][u]=t;
	}

	auto d1=dijkstra(g, adj, n, x);
	auto d2=dijkstra(g_rev, adj_rev, n, x);
	int ans=0;
	for(int i=0; i<n; ++i) {
		ans=max(d1[i]+d2[i], ans);
	}
	cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
