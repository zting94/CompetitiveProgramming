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

const int mxN=501;
const int mx=1e8;
int a[mxN];
int sum[mxN];
int cache[mxN][mxN];
int n;

int dp(int l, int r) {
	if(l+1==r)
		return a[l]+a[r];
	if(l>=r)
		return 0;
	int& ret=cache[l][r];
	if(ret!=-1)
		return ret;
	ret=mx;
	for(int i=l; i<=r; ++i) {
		ret=min(ret, dp(l, i)+dp(i+1, r));
	}
	return ret+=sum[r+1]-sum[max(l, 0)];
}

void solve() {
	cin >> n;
	memset(cache, -1, sizeof(cache));
	sum[0]=0;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		sum[i+1]=sum[i]+a[i];
	}
	print(dp(0, n-1));
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
