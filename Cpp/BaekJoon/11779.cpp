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

const int mxN=1e3+1;
const ll mxD=1e18;
int n, m, s, e;
vector<pair<int, ll>> adj[mxN];
int b[mxN];
ll d[mxN];

void solve() {
	cin >> n >> m;
	for(int i=0; i<n; ++i) {
		d[i]=mxD;
		b[i]=-1;
	}
	for(int i=0; i<m; ++i) {
		int u, v;
		ll w;
		cin >> u >> v >> w, --u, --v;
		adj[u].push_back({v, w});
	}
	cin >> s >> e, --s, --e;
	priority_queue<pair<ll, int>> pq;
	pq.push({0, s});
	d[s]=0;
	while(!pq.empty()) {
		auto [cost, u]=pq.top();
		pq.pop();
		for(auto [v, w] : adj[u]) {
			if(d[v]>w-cost) {
				d[v]=w-cost;
				b[v]=u;
				pq.push({cost-w, v});
			}
		}
	}
	print(d[e]);
	vector<int> ans{e+1};
	while(b[e]!=-1) {
		ans.push_back(b[e]+1);
		e=b[e];
	}
	reverse(ans.begin(), ans.end());
	print(ans.size());
	print(ans);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
