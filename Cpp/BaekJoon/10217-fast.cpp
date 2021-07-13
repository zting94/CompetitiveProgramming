#include <bits/stdc++.h>

/* Dijkstra */

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

class Edge {
public :
	Edge() {}
	Edge(int vv, int cc, int dd)
		: v(vv), c(cc), d(dd) {}
	int u, v, c, d;
};

bool operator<(const Edge& l, const Edge& r) {
	return l.d>r.d;
}

const int mx=1e9;

void solve() {
	int N, M, K;
	cin >> N >> M >> K;
	vvi dp(N+1, vi(M+1, mx));
	vector<bool> vis(N+1, false);
	vector<Edge> adj[N];
	for(int i=0; i<K; ++i) {
		int u, v, c, d;
		cin >> u >> v >> c >> d, --u, --v;
		adj[u].push_back({v, c, d});
	}
	dp[0][0]=0;
	while(1) {
		int next=-1, minD=mx;
		for(int i=0; i<N; ++i) {
			if(vis[i])
				continue;
			for(int j=0; j<=M; ++j) {
				if(dp[i][j]<minD) {
					next=i;
					minD=dp[i][j];
				}
			}
		}
		if(next==-1)
			break;
		vis[next]=true;
		for(int i=0; i<=M; ++i) {
			if(dp[next][i]>=mx)
				continue;
			for(Edge e : adj[next]) {
				if(i+e.c>M)
					continue;
				if(dp[e.v][i+e.c]>e.d+dp[next][i]) 
					dp[e.v][i+e.c]=e.d+dp[next][i];
			}
		}
	}
	int ans=mx;
	for(int i=0; i<=M; ++i) 
		ans=min(ans, dp[N-1][i]);
	if(ans>=mx)
		print("Poor KCM");
	else
		print(ans);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int tt;
	cin >> tt;
	while(tt--)
    	solve();

    return 0;
}
