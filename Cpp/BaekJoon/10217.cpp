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
	vector<Edge> adj[N];
	for(int i=0; i<K; ++i) {
		int u, v, c, d;
		cin >> u >> v >> c >> d, --u, --v;
		adj[u].push_back({v, c, d});
	}
	priority_queue<Edge> pq;
	pq.push(Edge(0, 0, 0));
	dp[0][0]=0;
	while(!pq.empty()) {
		Edge e=pq.top();
		pq.pop();
		for(Edge next : adj[e.v]) {
			if(e.c+next.c>M)
				continue;
			if(dp[next.v][e.c+next.c]>e.d+next.d) {
				dp[next.v][e.c+next.c]=e.d+next.d;
				pq.push(Edge(next.v, e.c+next.c, e.d+next.d));
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
