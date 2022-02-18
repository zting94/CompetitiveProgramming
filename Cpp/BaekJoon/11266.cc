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
const int mxV=1e4+1;
int V, E, C, A[mxV];
vi adj[mxV];
set<int> ans;
bool vis[mxV];

int dfs(int u, bool root) {
	vis[u]=1;
	A[u]=++C;
	int ret=A[u], child=0;
	for(int v : adj[u]) {
		if(vis[v])
			ret=min(ret, A[v]);
		else {
			++child;
			int mn=dfs(v, 0);
			if(!root&&mn>=A[u])
				ans.insert(u+1);
			ret=min(ret, mn);
		}
	}
	if(root&&child>=2)
		ans.insert(u+1);
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
			dfs(i, 1);
	print(ans.size());
	for(int i : ans)
		cout << i << " ";
	cout << nl;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
