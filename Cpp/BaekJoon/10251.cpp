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

void __zbg(int v) { cerr << v; }
void __zbg(long v) { cerr << v; }
void __zbg(ll v) { cerr << v; }
void __zbg(unsigned v) { cerr << v; }
void __zbg(unsigned long v) { cerr << v; }
void __zbg(ull v) { cerr << v; }
void __zbg(float v) { cerr << v; }
void __zbg(double v) { cerr << v; }
void __zbg(long double v) { cerr << v; }
void __zbg(char v) { cerr << '\'' << v << '\''; }
void __zbg(const char* v) { cerr << '\'' << v << '\''; }
void __zbg(const string& v) { cerr << '\'' << v << '\''; }
void __zbg(bool v) { cerr << v?"true":"false"; }

template<typename T, typename V>
void __zbg(const pair<T, V>& v) {
	cerr << '{';
	__zbg(v.first);
	cerr << ", ";
	__zbg(v.second);
	cerr << '}';
}

template<typename T>
void __zbg(const T& x) {
	int f=0;
	cerr << '{';
	for (auto &i : x) {
		cerr << (f++?", ":"");
		__zbg(i);
	}
	cerr << '}';
}

void _zbg() { cerr << "]\n"; }

template<typename T, typename... V>
void _zbg(T t, V... v) {
	__zbg(t);
	if(sizeof...(v))
		cerr << ", ";
	_zbg(v...);
}
//#define dbg(x...) cerr << "\033[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _zbg(x); cerr << "\033[39m" << endl;
#define dbg(x...) cerr << __func__<<":"<<__LINE__<<" [" << #x << "] = ["; _zbg(x); cerr << endl;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).begin(), (x).end()

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

const int mxN=101, mx=1e6+7;
int dp[mxN][mxN][mxN*2][2], H[mxN][mxN], V[mxN][mxN], M, N, G, L;

void solve() {
	cin >> M >> N >> L >> G;
	for(int i=0; i<M; ++i)
		for(int j=0; j<N-1; ++j)
			cin >> H[i][j];
	for(int i=0; i<M-1; ++i)
		for(int j=0; j<N; ++j)
			cin >> V[i][j];
	for(int i=0; i<mxN; ++i)
		for(int j=0; j<mxN; ++j)
			for(int k=0; k<mxN*2; ++k)
				for(int d=0; d<2; ++d)
					dp[i][j][k][d]=mx;
	dp[0][0][0][0]=dp[0][0][0][1]=0;
	for(int i=1; i<N; ++i)
		dp[0][i][0][1]=dp[0][i-1][0][1]+H[0][i-1];
	for(int i=1; i<M; ++i)
		dp[i][0][0][0]=dp[i-1][0][0][0]+V[i-1][0];
	for(int i=1; i<M; ++i) {
		for(int j=1; j<N; ++j) {
			for(int k=0; k<mxN*2; ++k) {
				dp[i][j][k][0]=dp[i-1][j][k][0]+V[i-1][j];
				dp[i][j][k][1]=dp[i][j-1][k][1]+H[i][j-1];
				if(k>0) {
					dp[i][j][k][0]=min(dp[i][j][k][0], dp[i-1][j][k-1][1]+V[i-1][j]);
					dp[i][j][k][1]=min(dp[i][j][k][1], dp[i][j-1][k-1][0]+H[i][j-1]);
				}
			}
		}
	}
	for(int k=0; k<mxN*2; ++k) {
		if(dp[M-1][N-1][k][0]<=G||dp[M-1][N-1][k][1]<=G) {
			print(L*(N+M-2)+k);
			return;
		}
	}
	print(-1);
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
