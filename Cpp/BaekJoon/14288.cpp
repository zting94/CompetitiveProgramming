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
int N, M, tree[mxN*4], tree2[mxN*4], f, S[mxN], E[mxN], s=-1, lazy[mxN*4];
vi adj[mxN];

void dfs(int u) {
	S[u]=++s;
	for(int v : adj[u])
		dfs(v);
	E[u]=s;
}

void prop(int i, int s, int e) {
	if(!lazy[i])
		return;
	tree[i]+=(e-s+1)*lazy[i];
	if(s!=e) {
		lazy[i*2]+=lazy[i];
		lazy[i*2+1]+=lazy[i];
	}
	lazy[i]=0;
}

int update(int i, int s, int e, int l, int r, int w) {
	prop(i, s, e);
	if(e<l||r<s)
		return tree[i];
	if(l<=s&&e<=r) {
		lazy[i]=w;
		prop(i, s, e);
		return tree[i];
	}
	int m=(s+e)/2;
	return tree[i]=update(i*2, s, m, l, r, w)+update(i*2+1, m+1, e, l, r, w);
}

int query(int i, int s, int e, int l, int r) {
	prop(i, s, e);
	if(e<l||r<s)
		return 0;
	if(l<=s&&e<=r)
		return tree[i];
	int m=(s+e)/2;
	return query(i*2, s, m, l, r)+query(i*2+1, m+1, e, l, r);
}

int update2(int i, int s, int e, int l, int r, int w) {
	if(e<l||r<s)
		return tree2[i];
	if(l<=s&&e<=r) {
		return tree2[i]+=w;
	}
	int m=(s+e)/2;
	return tree2[i]=update2(i*2, s, m, l, r, w)+update2(i*2+1, m+1, e, l, r, w);
}

int query2(int i, int s, int e, int l, int r) {
	if(e<l||r<s)
		return 0;
	if(l<=s&&e<=r)
		return tree2[i];
	int m=(s+e)/2;
	return query2(i*2, s, m, l, r)+query2(i*2+1, m+1, e, l, r);
}

void solve() {
	int t;
	cin >> N >> M >> t;
	for(int i=1; i<N; ++i) {
		cin >> t, --t;
		adj[t].push_back(i);
	}
	dfs(0);
	while(M--) {
		int c, i, w;
		cin >> c;
		if(c==3)
			f=1-f;
		else if(c==2) {
			cin >> i, --i;
			print(query(1, 0, N-1, S[i], S[i])+query2(1, 0, N-1, S[i], E[i]));
		} else {
			cin >> i >> w, --i;
			if(f)
				update2(1, 0, N-1, S[i], S[i], w);
			else
				update(1, 0, N-1, S[i], E[i], w);
		}
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
