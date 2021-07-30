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

const int mxN=105;
int N, dp[mxN+1][mxN+1];
vector<pii> A;

bool can(const pii& l, const pii& r) {
	if(l.first<=r.first&&l.second<=r.second) 
		return true;
	if(l.first<=r.second&&l.second<=r.first)
		return true;
	return false;
}

// i = current
// j = last
int dfs(int i, int j) {
	if(i==N)
		return 0;
	int& ret=dp[i][j];
	if(ret!=-1)
		return ret;
	ret=dfs(i+1, j);
	if(can(A[i], A[j]))
		ret=max(ret, dfs(i+1, i)+1);
	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for(int i=0, f, s; i<N; ++i) {
		cin >> f >> s;
		if(f<s)
			swap(f, s);
		A.push_back({f, s});
	}
	A.push_back({1e9, 1e9});
	N=A.size();
	sort(A.rbegin(), A.rend());
	print(dfs(1, 0));
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
