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

const int mxN=1e3;
int n, a[mxN+1], dp[mxN+1][mxN+1][2];

int dfs(int l, int r, int s) {
	if(l==r)
		return s==1?a[l]:0;
	int& ret=dp[l][r][s];
	if(ret!=-1)
		return ret;
	if(s==1) 
		ret=max(dfs(l+1, r, 0)+a[l], dfs(l, r-1, 0)+a[r]);
	else 
		ret=min(dfs(l+1, r, 1), dfs(l, r-1, 1));
	
	return ret;
}


void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> n;
	read(a, n);
	print(dfs(0, n-1, 1));
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int tt;
	cin >> tt;
	while(tt--)
    	solve();

    return 0;
}
