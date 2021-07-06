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

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	int r=(k-1)/m;
	int c=(k-1)%m;
	vvi dp(n, vi(m, 0));
	if(k==0) {
		for(int i=0; i<n; ++i)
			dp[i][0]=1;
		for(int j=0; j<m; ++j)
			dp[0][j]=1;
		for(int i=1; i<n; ++i) {
			for(int j=1; j<m; ++j) {
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
			}
		}
		print(dp[n-1][m-1]);
	} else {
		for(int i=0; i<=r; ++i)
			dp[i][0]=1;
		for(int j=0; j<=c; ++j)
			dp[0][j]=1;
		for(int i=1; i<=r; ++i) {
			for(int j=1; j<=c; ++j) {
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
			}
		}
		int v=dp[r][c];
		dp[r][c]=1;
		for(int i=r+1; i<n; ++i)
			dp[i][c]=1;
		for(int j=c+1; j<m; ++j)
			dp[r][j]=1;
		for(int i=r+1; i<n; ++i) {
			for(int j=c+1; j<m; ++j) {
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
			}
		}
		print(v*dp[n-1][m-1]);
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
