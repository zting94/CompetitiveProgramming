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
ll dp[101][11];

void pre() {
	for(int i=0; i<10; ++i)
		dp[1][i]=1;
	for(int i=1; i<=80; ++i) 
		for(int j=0; j<10; ++j)
			for(int k=0; k<=j; ++k)
				dp[i+1][k]+=dp[i][j];
}

void solve() {
	string S;
	cin >> S;
	int N=S.size();
	for(int i=1; i<N; ++i)
		if(S[i]<S[i-1]) {
			print(-1);
			return;
		}
	ll ans=dp[N+1][0];
	for(int i=0; i<N; ++i)
		for(int j=S[i]-'0'+1; j<10; ++j)
			ans-=dp[N-i][j];
	print(ans-1);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	pre();

	int tt;
	cin >> tt;
	while(tt--)
		solve();

    return 0;
}
