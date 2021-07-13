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

const int mxN=300, mxM=20;
int dp[mxM+1][mxN+1];
int a[mxM+1][mxN+1], n, m, ans, asset[mxM+1];
bool vis[mxM+1];

int dfs(int i, int remain) {
	if(i+1==m||remain<=0)
		return 0;
	int& ret=dp[i+1][remain];
	if(ret!=-1)
		return ret;
	ret=dfs(i+1, remain);
	for(int j=1; j<=n&&j<=remain; ++j) {
		ret=max(ret, dfs(i+1, remain-j)+a[i+1][j]);
	}
	return ret;
}

void reconstruct(int i, int remain) {
	if(i+1==m||remain<=0)
		return;
	reconstruct(i+1, remain);
	for(int j=1; j<=n&&j<=remain; ++j) {
		if(dfs(i+1, remain-j)+a[i+1][j]==ans) {
			asset[i+1]=j;
			ans-=a[i+1][j];
			reconstruct(i+1, remain-j);
			break;
		}
	}
}

void solve() {
	memset(dp, -1, sizeof(dp));
	memset(vis, 0, sizeof(vis));
	memset(asset, 0, sizeof(asset));
	cin >> n >> m;
	for(int i=0, t; i<n; ++i) {
		cin >> t;
		for(int j=0; j<m; ++j)
			cin >> a[j][t];
	}
	ans=dfs(-1, n);
	print(ans);
	reconstruct(-1, n);
	print(asset, m);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
