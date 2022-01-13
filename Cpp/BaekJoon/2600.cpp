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
const int mxN=501;
int A[3], K1, K2, dp[mxN][mxN][2];

int go(int i, int j, int f) {
	if(i==0&&j==0)
		return 0;
	int& ret=dp[i][j][f];
	if(ret!=-1)
		return ret;
	ret=0;
	for(int k=0; k<3; ++k) { 
		if(i>=A[k]&&!go(i-A[k], j, !f))
			return ret=1;
		if(j>=A[k]&&!go(i, j-A[k], !f))
			return ret=1;
	}
	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> A[0] >> A[1] >> A[2];
	for(int i=0; i<5; ++i) {
		cin >> K1 >> K2;
		if(go(K1, K2, 0))
			print("A");
		else
			print("B");
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
