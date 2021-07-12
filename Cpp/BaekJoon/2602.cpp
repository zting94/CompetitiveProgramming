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

const int mxN=100, mxM=20;
int dp[mxN+1][mxM+1][2];
string a, b, c;

int dfs(int i, int j, int st) {
	if(j==a.size())
		return 1;
	if(i+1==b.size())
		return j==a.size();
	int& ret=dp[i+1][j][st];
	if(ret!=-1)
		return ret;
	ret=dfs(i+1, j, st);
	if((st&&b[i+1]==a[j])||(!st&&c[i+1]==a[j])) 
		ret+=dfs(i+1, j+1, 1-st);
	return ret;
}

void solve() {	
	memset(dp, -1, sizeof(dp));
	cin >> a >> b >> c;
	print(dfs(-1, 0, 1)+dfs(-1, 0, 0));
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
