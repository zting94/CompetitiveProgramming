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

const int LOG=15;
const int mxN=3e4;
int N, M, depth[mxN+1], up[mxN+1][LOG];
vi adj[mxN+1];

void dfs(int u, int p) {
	depth[u]=depth[p]+1;
	up[u][0]=p;
	for(int v : adj[u])
		if(v!=p)
			dfs(v, u);
}

int LCA(int a, int b) {
	if(depth[a]<depth[b])
		swap(a, b);
	int k=depth[a]-depth[b];
	for(int i=LOG-1; i>=0; --i) 
		if(k&(1<<i)) 
			a=up[a][i];
	if(a==b)
		return a;
	for(int i=LOG-1; i>=0; --i) {
		if(up[a][i]!=up[b][i]) {
			a=up[a][i];
			b=up[b][i];
		}
	}
	return up[a][0];
}

void solve() {
	cin >> N;
	for(int i=0, u, v; i<N-1; ++i) {
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	depth[0]=-1;
	dfs(0, 0);
	for(int j=1; j<LOG; ++j) 
		for(int i=0; i<N; ++i)
			up[i][j]=up[up[i][j-1]][j-1];
	cin >> M;
	int ans=0;
	for(int i=0, u=0, v; i<M; ++i) {
		cin >> v, --v;
		ans+=depth[u]+depth[v]-2*depth[LCA(u, v)];
		u=v;
	}
	print(ans);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
