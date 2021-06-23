#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int mxN=1e5+1;
vector<pair<int, int>> adj[mxN];
vector<bool> vis;
int n;
ll ans;

ll dfs(int u, int par) {
	if(vis[u])
		return 0;
	vis[u]=true;
	ll d=0;
	for(auto& [v, w] : adj[u]) {
		if(v==par)
			continue;
		ll cur=dfs(v, u)+w+d;
		ans=max(ans, cur);
		d=max(d, cur-d);
	}
	return d;
}

void solve() {
	cin >> n;
	ans=0;
	vis=vector<bool>(n+1, false);
	for(int i=0; i<n; ++i) {
		int u;
		cin >> u;
		while(true) {
			int v, w;
			cin >> v;
			if(v==-1)
				break;
			cin >> w;
			adj[u].push_back({v, w});
		}
	}
	dfs(1, -1);

	cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
