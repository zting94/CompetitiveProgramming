#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int mxN=1e4+1;
vector<pair<int, int>> adj[mxN];
bool vis[mxN];
int n;
int ans;

int dfs(int u) {
	if(vis[u])
		return 0;
	vis[u]=true;
	int d=0;
	for(auto& [v, w] : adj[u]) {
		int cur=dfs(v)+w+d;
		ans=max(ans, cur);
		d=max(d, cur-d);
	}
	return d;
}

void solve() {
	cin >> n;
	ans=0;
	memset(vis, 0, sizeof(vis));
	for(int i=0; i<n-1; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}
	dfs(1);
	cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
