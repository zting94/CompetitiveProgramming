#include <bits/stdc++.h>

using namespace std;

using ll=long long;
using ull=unsigned long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
using vii=vector<pii>;
using vll=vector<pll>;
using vi=vector<int>;
using vl=vector<ll>;
using vvi=vector<vi>;
using vvl=vector<vl>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define nl '\n'

template<typename T>
void print(const vector<T>& v, string sp=" ") {
	for(int i=0; i<v.size(); ++i) {
		if(i>0)
			cout << sp;
		cout << v[i];
	}
	cout << '\n';
}

template<typename T>
void print(const vector<vector<T>>& v, string sp=" ") {
	for(auto& vv : v)
		print(vv, sp);
}

template<typename T>
void print(T v) {
	cout << v << '\n';
}

template<typename T>
void print(T v[], int sz, string sp=" ") {
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

void solve() {
	string A, B;
	cin >> A >> B;
	int N=A.size(), M=B.size();
	vvi dp(N+1, vi(M+1));
	for(int i=1; i<=N; ++i) {
		for(int j=1; j<=M; ++j) {
			if(A[i-1]==B[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		}
	}
	print(dp[N][M]);
}

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}
