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

const int D1=10000, D3=25000, D5=37000;
const int mxN=102, mx=1e7;
int n, m, a[mxN], dp[mxN][mxN];

int dfs(int i, int j) {
	if(i+1>n)
		return 0;
	if(a[i+1]==-1)
		return dfs(i+1, j);
	int& ret=dp[i][j];
	if(ret!=-1)
		return ret;
	ret=mx;
	if(j>=3)
		ret=min(ret, dfs(i+1, j-3));
	ret=min(ret, dfs(i+1, j)+D1);
	ret=min(ret, dfs(i+3, j+1)+D3);
	return ret=min(ret, dfs(i+5, j+2)+D5);
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for(int i=0, v; i<m; ++i) {
		cin >> v;
		a[v]=-1;
	}
	print(dfs(0, 0));
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
