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

const int mxN=101, mxL=81;
const int dr[4]={-1, 0, 0, 1};
const int dc[4]={0, -1, 1, 0};
int N, M, K, dp[mxL][mxN][mxN];
vector<string> a;
string s;

bool valid(int r, int c) {
	return r>=0&&c>=0&&N>r&&M>c;
}

int dfs(int i, int r, int c) {
	if(!valid(r, c)||a[r][c]!=s[i])
		return 0;
	if(i==s.size()-1)
		return a[r][c]==s[i];
	int& ret=dp[i][r][c];
	if(ret!=-1)
		return ret;
	ret=0;
	for(int k=1; k<=K; ++k) 
		for(int t=0; t<4; ++t) 
			ret+=dfs(i+1, r+dr[t]*k, c+dc[t]*k);
	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> N >> M >> K;
	a.resize(N);
	for(auto& i : a)
		cin >> i;
	cin >> s;
	int ans=0;
	for(int i=0; i<N; ++i) 
		for(int j=0; j<M; ++j) 
			ans+=dfs(0, i, j);
	print(ans);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
