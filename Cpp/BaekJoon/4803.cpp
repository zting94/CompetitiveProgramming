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

const int dx[4]={-1, 0, 1, 0}, dy[4]={0, -1, 0, 1};
const int mxN=501;
int N, M, p[mxN];
vi adj[mxN];
bool vis[mxN];

int dfs(int u, int p) {
	vis[u]=1;
	int ret=1;
	for(int v : adj[u]) {
		if(v==p)
			continue;
		if(vis[v])
			return 0;
		ret&=dfs(v, u);
	}
	return ret;
}

int solve() {
	memset(vis, 0, sizeof(vis));
	for(int i=0; i<N; ++i) {
		adj[i].clear();
		p[i]=i;
	}
	for(int i=0; i<M; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ans=0;
	for(int i=0; i<N; ++i)
		if(!vis[i])
			ans+=dfs(i, i);
	return ans;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int tc=1;
	while(1) {
		cin >> N >> M;
		if(N==0)
			break;
		int ans=solve();
		cout << "Case " << tc << ": ";
		if(ans==0)
			cout << "No trees." << nl;
		else if(ans==1)
			cout << "There is one tree." << nl;
		else
			cout << "A forest of " << ans << " trees." << nl;
		++tc;
	}

    return 0;
}
