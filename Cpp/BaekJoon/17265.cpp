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
void __zbg(bool v) { cerr << (v?"true":"false"); }

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

const int mxN=6, mx=1e6, mn=-1e6, M=3200;
char A[mxN][mxN];
int N, dp[mxN][mxN][M*2+2][3][2];

bool isop(char c) {
	return c=='+'||c=='-'||c=='*';
}

int calc(int s, int i, int j, char op) {
	int v=A[i][j]-'0';
	if(op=='+')
		s+=v;
	else if(op=='*')
		s*=v;
	else
		s-=v;
	return s;
}

int toInt(char c) {
	if(c=='+')
		return 0;
	else if(c=='*')
		return 1;
	return 2;
}

int dfs1(int i, int j, char op, int s) {
	if(i==N-1&&j==N-1)
		return calc(s, i, j, op);
	if(i>=N||j>=N)
		return mn;
	int& ret=dp[i][j][s+M][toInt(op)][0];
	if(ret!=-1)
		return ret;
	char c=A[i][j];
	if(isop(c)) {
		return ret=max(dfs1(i+1, j, c, s), dfs1(i, j+1, c, s));
	} else {
		s=calc(s, i, j, op);
		return ret=max(dfs1(i+1, j, '+', s), dfs1(i, j+1, '+', s));
	}
}

int dfs2(int i, int j, char op, int s) {
	if(i==N-1&&j==N-1)
		return calc(s, i, j, op);
	if(i>=N||j>=N)
		return mx;
	int& ret=dp[i][j][s+M][toInt(op)][1];
	if(ret!=-1)
		return ret;
	char c=A[i][j];
	if(isop(c)) {
		return ret=min(dfs2(i+1, j, c, s), dfs2(i, j+1, c, s));
	} else {
		s=calc(s, i, j, op);
		return ret=min(dfs2(i+1, j, '+', s), dfs2(i, j+1, '+', s));
	}

}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for(int i=0; i<N; ++i)
		for(int j=0; j<N; ++j)
			cin >> A[i][j];
	cout << dfs1(0, 0, '+', 0) << ' ' << dfs2(0, 0, '+', 0) << nl;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
