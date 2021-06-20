#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int mx=1e8;
const int mxN=801;
int N, E;
vector<vector<int>> adj;
vector<vector<int>> g;

vector<int> dijkstra(int start) {
	vector<int> dist(N, mx);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, start});
	while(!pq.empty()) {
		auto [d, u]=pq.top();
		pq.pop();
		if(d>dist[u])
			continue;
		dist[u]=d;
		for(int next:adj[u]) {
			if(d+g[u][next]<dist[next])
				pq.push({d+g[u][next], next});
		}
	}
	return dist;
}

void solve() {
	cin >> N >> E;
	adj=vector<vector<int>>(N);
	g=vector<vector<int>>(N, vector<int>(N, mx));
	for(int i=0; i<E; ++i) {
		int u, v, c;
		cin >> u >> v >> c, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		g[u][v]=g[v][u]=c;
	}
	int v1, v2;
	cin >> v1 >> v2, --v1, --v2;
	auto d1=dijkstra(0);
	auto d2=dijkstra(v1);
	auto d3=dijkstra(v2);

	int ans1=d1[v1]+d2[v2]+d3[N-1];
	int ans2=d1[v2]+d3[v1]+d2[N-1];
	int ans=min(ans1, ans2);
	cout << (ans>=mx ? -1 : ans) << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
