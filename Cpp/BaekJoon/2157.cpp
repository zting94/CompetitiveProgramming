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

const int mxN=302, mn=-1e9;
int N, M, K, dp[mxN][mxN];
vii adj[mxN];

int dfs(int i, int m) {
	if(m==M)
		return (i==N-1)?0:mn;
	if(i==N-1)
		return 0;
	int& ret=dp[i][m];
	if(ret!=-1)
		return ret;
	ret=mn;
	for(auto [v, cost] : adj[i]) 
		if(v>i)
			ret=max(ret, dfs(v, m+1)+cost);
	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> N >> M >> K;
	for(int i=0; i<K; ++i) {
		int u, v, c;
		cin >> u >> v >> c, --u, --v;
		adj[u].push_back({v, c});
	}
	print(dfs(0, 1));
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
