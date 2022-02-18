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
const int mxN=1e5+1;
int N, Q, A[mxN], seq[mxN], sz[mxN], depth[mxN], top_node[mxN], par[mxN], s;
int tree[mxN*4];
vi adj[mxN];

void dfs(int u, int p, int d) {
	sz[u]=1;
	par[u]=p;
	depth[u]=d;
	for(int v : adj[u]) {
		if(v!=p) {
			dfs(v, u, d+1);
			sz[u]+=sz[v];
		}
	}
}

void dfs2(int u, int p, int top) {
	seq[u]=s++;
	top_node[u]=top;
	int mi=-1, ms=-1;
	for(int v : adj[u]) {
		if(v!=p&&ms<sz[v]) {
			mi=v;
			ms=sz[v];
		}
	}
	if(mi==-1)
		return;
	dfs2(mi, u, top);
	for(int v : adj[u])
		if(v!=p&&v!=mi)
			dfs2(v, u, v);
}

int update(int i, int s, int e, int idx, int v) {
	if(e<idx||idx<s)
		return tree[i];
	if(s==e)
		return tree[i]=v;
	int m=(s+e)/2;
	return tree[i]=update(i*2, s, m, idx, v)^update(i*2+1, m+1, e, idx, v);
}

int query(int i, int s, int e, int l, int r) {
	if(e<l||r<s)
		return 0;
	if(l<=s&&e<=r)
		return tree[i];
	int m=(s+e)/2;
	return query(i*2, s, m, l, r)^query(i*2+1, m+1, e, l, r);
}

int Qu(int u, int v) {
	int ret=0;
	while(top_node[u]!=top_node[v]) {
		if(depth[top_node[u]]<depth[top_node[v]])
			swap(u, v);
		ret^=query(1, 0, N-1, seq[top_node[u]], seq[u]);
		u=par[top_node[u]];
	}
	if(seq[u]>seq[v])
		swap(u, v);
	ret^=query(1, 0, N-1, seq[u], seq[v]);
	return ret;
}

void solve() {
	cin >> N >> Q;
	read(A, N);
	for(int i=0; i<N-1; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0, 0, 0);
	dfs2(0, 0, 0);
	for(int i=0; i<N; ++i)
		update(1, 0, N-1, seq[i], A[i]);
	while(Q--) {
		int c, i, j;
		cin >> c >> i >> j;
		if(c==1) {
			--i;
			update(1, 0, N-1, seq[i], j);
		} else {
			--i, --j;
			print(Qu(i, j));
		}
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
