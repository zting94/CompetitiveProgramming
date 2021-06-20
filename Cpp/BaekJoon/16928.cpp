#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int n, m;
	cin >> n >> m;
	unordered_map<int, int> rope, snake;
	for(int i=0; i<n; ++i) {
		int u, v;
		cin >> u >> v;
		rope[u]=v;
	}
	for(int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v;
		snake[u]=v;
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0, 1});
	vector<bool> v(101, false);
	while(!q.empty()) {
		auto [d, u]=q.top();
		q.pop();
		if(u>100||v[u]) 
			continue;
		if(u==100) {
			cout << d << '\n';
			return;
		}
		v[u]=true;
		if(rope.find(u)!=rope.end()) {
			q.push({d, rope[u]});
			continue;
		}
		if(snake.find(u)!=snake.end()) {
			q.push({d, snake[u]});
			continue;
		}
		for(int i=1; i<=6; ++i) 
			q.push({d+1, u+i});
	}
	assert(false);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
