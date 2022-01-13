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
const int mx=1e9+7;

void solve() {
	int N, T, C;
	cin >> N >> T >> C, --C;
	vector<vii> adj(N);
	for(int i=0; i<T; ++i) {
		int u, v, d;
		cin >> u >> v >> d, --u, --v;
		adj[v].push_back({d, u});
	}
	vi dist(N, mx);
	priority_queue<pii> pq;
	pq.push({0, C});
	dist[C]=0;
	while(!pq.empty()) {
		auto [d, u]=pq.top();
		pq.pop();
		for(auto [nd, v] : adj[u]) {
			if(dist[u]+nd<dist[v]) {
				dist[v]=dist[u]+nd;
				pq.push({-nd, v});
			}
		}
	}
	int cnt=0, ans=0;
	for(int i=0; i<N; ++i) {
		if(dist[i]==mx)
			continue;
		++cnt;
		ans=max(ans, dist[i]);
	}
	cout << cnt << ' ' << ans << nl;
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
