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
const int mxN=500, mx=1e9;
int N, K, x[mxN], y[mxN], dp[mxN][mxN];

int dst(int i, int j) {
	return abs(x[i]-x[j])+abs(y[i]-y[j]);
}

int go(int i, int k) {
	if(i>N)
		return mx;
	if(i==N-1)
		return 0;
	int& ret=dp[i][k];
	if(ret!=-1)
		return ret;
	ret=mx;
	for(int j=0; j<=k; ++j)
		ret=min(ret, go(i+j+1, k-j)+dst(i, i+j+1));
	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> N >> K;
	for(int i=0; i<N; ++i)
		cin >> x[i] >> y[i];
	print(go(0, K));
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
