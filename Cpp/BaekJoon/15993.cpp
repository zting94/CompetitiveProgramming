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
const int mxN=1e5+1;
const ll M=1e9+9;
int N;
ll dp[mxN][2];

ll go(int n, int k) {
	if(!k&&n>0&&n<=3) 
		return n==3?2:1;
	if(n<=0)
		return 0;
	ll& ret=dp[n][k];
	if(ret!=-1)
		return ret;
	return ret=(go(n-1, !k)+go(n-2, !k)+go(n-3, !k))%M;
}

void solve() {
	cin >> N;
	cout << go(N, 0) << " " << go(N, 1) << nl;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	memset(dp, -1, sizeof(dp));

	int tt;
	cin >> tt;
	while(tt--)
		solve();

    return 0;
}
