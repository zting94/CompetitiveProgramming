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
   	for(auto& i : x) {
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
int N, M, dp[mxN][mxN];
string s[mxN];
bool v[mxN][mxN];

int go(int i, int j) {
	if(i<0||j<0||i>=N||j>=M)
		return 1;
	if(v[i][j])
		return 0;
	int& ret=dp[i][j];
	if(ret!=-1)
		return ret;
	v[i][j]=1;
	if(s[i][j]=='U')
		ret=go(i-1, j);
	else if(s[i][j]=='R')
		ret=go(i, j+1);
	else if(s[i][j]=='D')
		ret=go(i+1, j);
	else
		ret=go(i, j-1);
	v[i][j]=0;
	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	memset(v, 0, sizeof(v));
	cin >> N >> M;
	for(int i=0; i<N; ++i)
		cin >> s[i];
	int ans=0;
	for(int i=0; i<N; ++i)
		for(int j=0; j<M; ++j)
			ans+=go(i, j);
	print(ans);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
