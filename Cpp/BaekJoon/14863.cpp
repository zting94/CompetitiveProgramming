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

const int mxN=1e2+1, mxK=1e5+1;
int N, K, A[mxN][4], dp[mxN][mxK];

int go(int i, int k) {
	if(k<0)
		return -1e7;
	if(k==0)
		return i==N?0:-1e7;
	if(i==N)
		return 0;
	int& ret=dp[i][k];
	if(ret!=-1)
		return ret;
	ret=go(i+1, k-A[i][0])+A[i][1];
	return ret=max(ret, go(i+1, k-A[i][2])+A[i][3]);
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> N >> K;
	for(int i=0; i<N; ++i)
		for(int j=0; j<4; ++j)
			cin >> A[i][j];
	print(go(0, K));
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
