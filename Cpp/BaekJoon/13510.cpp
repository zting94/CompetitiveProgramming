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
int N, M, tree[mxN*4], sz[mxN], par[mxN], seq[mxN], depth[mxN], top_node[mxN], se;
int eu[mxN], ev[mxN], cost[mxN];
vi adj[mxN];

int update(int i, int s, int e, int l, int r, int v) {
	if(e<l||r<s)
		return tree[i];
	if(l<=s&&e<=r)
		return tree[i]=v;
	int m=(s+e)/2;
	return tree[i]=max(update(i*2, s, m, l, r, v), update(i*2+1, m+1, e, l, r, v));
}

int query(int i, int s, int e, int l, int r) {
	if(e<l||r<s)
		return 0;
	if(l<=s&&e<=r)
		return tree[i];
	int m=(s+e)/2;
	return max(query(i*2, s, m, l, r), query(i*2+1, m+1, e, l, r));
}

void dfs(int u, int p, int d) {
	sz[u]=1;
	depth[u]=d;
	par[u]=p;
	for(int v : adj[u]) {
		if(v!=p) {
			dfs(v, u, d+1);
			sz[u]+=sz[v];
		}
	}
}

void dfs2(int u, int p, int top) {
	seq[u]=se++;
	top_node[u]=top;
	int mi=-1, ms=-1;
	for(int v : adj[u]) {
		if(v!=p&&sz[v]>ms) {
			mi=v;
			ms=sz[v];
		}
	}
	if(mi==-1)
		return;
	dfs2(mi, u, top);
	for(int v : adj[u]) {
		if(v!=p&&v!=mi)
			dfs2(v, u, v);
	}
}

int Get(int u, int v) {
	int ret=0;
	while(top_node[u]!=top_node[v]) {
		if(depth[top_node[u]]<depth[top_node[v]])
			swap(u, v);
		ret=max(ret, query(1, 0, N-1, seq[top_node[u]], seq[u]));
		u=par[top_node[u]];
	}
	if(seq[u]>seq[v])
		swap(u, v);
	return ret=max(ret, query(1, 0, N-1, seq[u]+1, seq[v]));
}

void solve() {
	cin >> N;
	for(int i=0; i<N-1; ++i) {
		cin >> eu[i] >> ev[i] >> cost[i], --eu[i], --ev[i];
		adj[eu[i]].push_back(ev[i]);
		adj[ev[i]].push_back(eu[i]);
	}
	dfs(0, 0, 0);
	dfs2(0, 0, 0);
	for(int i=0; i<N-1; ++i) {
		if(depth[eu[i]]>depth[ev[i]])
			swap(eu[i], ev[i]);
		update(1, 0, N-1, seq[ev[i]], seq[ev[i]], cost[i]);
	}
	cin >> M;
	while(M--) {
		int i, l, r;
		cin >> i >> l >> r;
		if(i==1) {
			--l;
			update(1, 0, N-1, seq[ev[l]], seq[ev[l]], r);
		} else {
			--l, --r;
			print(Get(l, r));
		}
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
