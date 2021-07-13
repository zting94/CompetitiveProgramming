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
int a[mxM+1][mxN+1], n, m;
int path[mxM+1][mxN+1];

void solve() {
	memset(dp, 0, sizeof(dp));
	cin >> n >> m;
	for(int i=0, t; i<n; ++i) {
		cin >> t;
		for(int j=0; j<m; ++j)
			cin >> a[j][t];
	}
	for(int i=1; i<=m; ++i) {
		for(int cost=1; cost<=n; ++cost) {
			for(int j=0; j<=cost; ++j) {
				int tmp=dp[i-1][cost-j]+a[i-1][j];
				if(tmp>dp[i][cost]) {
					dp[i][cost]=tmp;
					path[i][cost]=j;
				}
			}
		}
	}
	print(dp[m][n]);
	vi ans;
	for(int i=m, cost=n; i>0; --i) {
		ans.push_back(path[i][cost]);
		cost-=path[i][cost];
	}
	reverse(all(ans));
	print(ans);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
