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
const int mxN=100;
string P, A;
int N, dp[mxN][mxN];

int go(int i, int j) {
	if(i==P.size())
		return j==A.size();
	if(j==A.size()) {
		if(i==P.size())
			return 1;
		if(P[i]=='*')
			return go(i+1, j);
		return 0;
	}
	int& ret=dp[i][j];
	if(ret!=-1)
		return ret;
	if(P[i]==A[j])
		return ret=go(i+1, j+1);
	if(P[i]=='*')
		return ret=go(i, j+1)|go(i+1, j+1)|go(i+1, j);
	return ret=0;
}

void solve() {
	cin >> P >> N;
	for(int i=0; i<N; ++i) {
		cin >> A;
		memset(dp, -1, sizeof(dp));
		if(go(0, 0)) 
			print(A);
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
