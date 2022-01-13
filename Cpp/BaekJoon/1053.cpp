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

const int mxN=51;
int dp[mxN][mxN], N;
string S;

int dfs(int l, int r) {
	if(l>=r)
		return 0;
	int& ret=dp[l][r];
	if(ret!=-1)
		return ret;
	return ret=min(min(dfs(l+1, r)+1, dfs(l, r-1)+1), dfs(l+1, r-1)+(S[l]!=S[r]));
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> S;
	N=S.size();
	int ans=dfs(0, N-1);
	for(int i=0; i<N-1; ++i) {
		for(int j=i+1; j<N; ++j) {
			memset(dp, -1, sizeof(dp));
			swap(S[i], S[j]);
			ans=min(ans, dfs(0, N-1)+1);
			swap(S[i], S[j]);
		}
	}
	print(ans);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
