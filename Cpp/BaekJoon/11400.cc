#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vii = vector<pii>;
using vll = vector<pll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define nl '\n'

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
void print(const vector<vector<T>>& v, char sp=' ') {
	for(auto& vv : v)
		print(vv, sp);
}

template<typename T>
void print(T v) {
	cout << v << '\n';
}

template<typename T>
void print(T v[], int sz, char sp=' ') {
	for(int i=0; i<sz; ++i) {
		if(i>0)
			cout << sp;
		cout << v[i];
	}
	cout << '\n';
}

template<typename T>
void read(vector<T>& v) {
	for(auto& x : v)
		cin >> x;
}

template<typename T>
void read(vector<vector<T>>& v) {
	for(auto& a : v)
		read(a);
}

template<typename T>
void read(T a[], int sz) {
	for(int i=0; i<sz; ++i)
		cin >> a[i];
}

const int dx[4]={-1, 0, 1, 0}, dy[4]={0, -1, 0, 1};
const int mxV=1e5+1;
int V, E, A[mxV], C;
vi adj[mxV];
set<pii> ans;
bool vis[mxV];

void add(int u, int v) {
	if(u<v)
		ans.insert({u, v});
	else
		ans.insert({v, u});
}

int dfs(int u, int p) {
	vis[u]=1;
	A[u]=++C;
	int ret=A[u];
	for(int v : adj[u]) {
		if(v==p)
			continue;
		if(vis[v]) {
			ret=min(ret, A[v]);
		} else {
			int mn=dfs(v, u);
			if(mn>A[u])
				add(u+1, v+1);
			ret=min(ret, mn);
		}
	}
	return ret;
}

void solve() {
	cin >> V >> E;
	for(int i=0; i<E; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0; i<V; ++i)
		if(!vis[i])
			dfs(i, i);
	print(ans.size());
	for(auto [u, v] : ans)
		cout << u << " " << v << nl;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
