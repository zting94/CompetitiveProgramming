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

const int mxN=101;
const int mxS=21;
int M, N;
ll dp[mxN][mxS];
int a[mxN];

ll dfs(int i, int sum) {
	if(i+1==N) 
		return sum==M;
	ll& ret=dp[i+1][sum];
	if(ret!=-1)
		return ret;
	ret=0;
	int t=sum+a[i+1];
	if(t>=0&&mxS>t)
		ret+=dfs(i+1, t);
	t=sum-a[i+1];
	if(t>=0&&mxS>t)
		ret+=dfs(i+1, t);

	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> N;
	read(a, N);
	M=a[N-1];
	--N;
	dfs(0, a[0]);
	print(dp[1][a[0]]);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
