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

const int mxN=1e5;
int N, dp[mxN+1][2], a[mxN+1], ans;
vi adj[mxN+1];
set<int> s;

int dfs(int u, int p, int pick) {
	int& ret=dp[u][pick];
	if(ret!=-1)
		return ret;
	ret=pick?a[u]:0;
	for(int v : adj[u]) {
		if(v==p)
			continue;
		if(pick) {
			ret+=dfs(v, u, 0);
		} else {
			ret+=max(dfs(v, u, 0), dfs(v, u, 1));
		}
	}
	return ret;
}

void reconstruct(int u, int p, int pick) {
	if(pick) {
		s.insert(u);
	}
	for(int v : adj[u]) {
		if(v==p)
			continue;
		if(pick) {
			reconstruct(v, u, 0);
		} else {
			if(dp[v][1]>dp[v][0])
				reconstruct(v, u, 1);
			else
				reconstruct(v, u, 0);
		}
	}
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for(int i=1; i<=N; ++i)
		cin >> a[i];
	for(int i=0, u, v; i<N-1; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	adj[0].push_back(1);
	ans=dfs(0, 0, 0);
	print(ans);
	reconstruct(0, 0, 0);
	for(int i : s)
		cout << i << ' ';
	cout << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
