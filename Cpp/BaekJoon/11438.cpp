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
const int mxN=1e5+1, LOG=16;
int N, M, depth[mxN], up[mxN][LOG];
vi adj[mxN];

void dfs(int u, int p, int d) {
	up[u][0]=p;
	depth[u]=d;
	for(int v : adj[u])
		if(v!=p)
			dfs(v, u, d+1);
}

int lca(int u, int v) {
	if(depth[u]<depth[v])
		swap(u, v);
	int k=depth[u]-depth[v];
	for(int i=LOG-1; i>=0; --i)
		if(k&(1<<i))
			u=up[u][i];
	if(u==v)
		return u+1;
	for(int i=LOG-1; i>=0; --i)
		if(up[u][i]!=up[v][i]) {
			u=up[u][i];
			v=up[v][i];
		}
	return up[u][0]+1;
}

void solve() {
	cin >> N;
	for(int i=0; i<N-1; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0, 0, 0);
	for(int j=1; j<LOG; ++j)
		for(int i=0; i<N; ++i)
			up[i][j]=up[up[i][j-1]][j-1];
	cin >> M;
	while(M--) {
		int u, v;
		cin >> u >> v, --u, --v;
		print(lca(u, v));
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
