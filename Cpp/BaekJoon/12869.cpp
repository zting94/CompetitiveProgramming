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

const int mxN=61;
int n, a[3], dp[mxN][mxN][mxN];

int dfs(int A, int B, int C) {
	A=max(0, A);
	B=max(0, B);
	C=max(0, C);
	if(A<=0&&B<=0&&C<=0)
		return 0;
	int& ret=dp[A][B][C];
	if(ret!=-1)
		return ret;
	ret=dfs(A-9, B-3, C-1)+1;
	ret=min(ret, dfs(A-9, B-1, C-3)+1);
	ret=min(ret, dfs(A-1, B-9, C-3)+1);
	ret=min(ret, dfs(A-3, B-9, C-1)+1);
	ret=min(ret, dfs(A-1, B-3, C-9)+1);
	return ret=min(ret, dfs(A-3, B-1, C-9)+1);
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> n;
	read(a, n);
	print(dfs(a[0], a[1], a[2]));
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
