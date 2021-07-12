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

const int mxN=50;
const int dr[4]={-1, 0, 0, 1};
const int dc[4]={0, -1, 1, 0};
int N, M, dp[mxN+1][mxN+1], ans;
bool vis[mxN+1][mxN+1];
string s[mxN+1];

bool can(int r, int c) {
	return r>=0&&c>=0&&N>r&&M>c&&s[r][c]!='H';
}

int dfs(int r, int c) {
	if(!can(r, c))
		return 0;
	if(vis[r][c]) {
		ans=-1;
		return 0;
	}
	int& ret=dp[r][c];
	if(ret!=-1) {
		return ret;
	}
	vis[r][c]=1;
	ret=1;
	for(int i=0; i<4; ++i) 
		ret=max(ret, 1+dfs(r+dr[i]*(s[r][c]-'0'), c+dc[i]*(s[r][c]-'0')));
	vis[r][c]=0;
	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	memset(vis, 0, sizeof(vis));
	cin >> N >> M;
	for(int i=0; i<N; ++i)
		cin >> s[i];
	int ret=dfs(0, 0);
	print(ans==-1?ans:ret);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
