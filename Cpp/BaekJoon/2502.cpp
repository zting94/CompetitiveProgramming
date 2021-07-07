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
	//a8 = a7+a6 = 13*a2 + 8*a1
	//a7 = a6+a5 = 8*a2 + 5*a1
	//a6 = a5+a4 = 5*a2 + 3*a1
	//a5 = a4+a3 = 3*a2 + 2*a1
	//a4 = a3+a2 = 2*a2 + a1
	//a3 = a2+a1
	int D, K;
	cin >> D >> K;
	vector<int> dp(D+1);
	dp[1]=dp[2]=1;
	for(int i=3; i<=D; ++i)
		dp[i]=dp[i-1]+dp[i-2];
	for(int i=1; i<=K; ++i) {
		for(int j=1; j<=K; ++j) {
			if(dp[D-1]*j+dp[D-2]*i==K) {
				cout << min(i, j) << '\n' << max(i, j) << '\n';
				return;
			}
		}
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
