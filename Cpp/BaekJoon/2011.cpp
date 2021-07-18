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

const int mxN=5e3, M=1e6;
int N, dp[mxN+1][27];
string s;

int dfs(int i, int v) {
	if(v<1||v>26)
		return 0;
	if(i+1>=N)
		return 1;
	int& ret=dp[i+1][v];
	if(ret!=-1)
		return ret;
	ret=0;
	ret=dfs(i+1, s[i+1]-'0')%M;
	if(i+2<N) 
		if((s[i+1]-'0')*10!=0)
			ret+=dfs(i+2, (s[i+1]-'0')*10+(s[i+2]-'0'))%M;
	return ret%=M;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> s;
	N=s.size();
	print(dfs(-1, 1));
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
