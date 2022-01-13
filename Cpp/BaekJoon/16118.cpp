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

class Wolf {
public :
	ll u, d, f;
};

bool operator<(const Wolf& l, const Wolf& r) {
	return l.d>r.d;
}

const int dx[4]={-1, 0, 1, 0}, dy[4]={0, -1, 0, 1};
const ll mxN=4e3+1, mx=1e10;
ll N, M, dist1[mxN], dist2[mxN][2], ans;
vll adj[mxN];

void di1() {
	priority_queue<pii> pq;
	pq.push({0, 0});
	dist1[0]=0;
	while(!pq.empty()) {
		auto [d, u]=pq.top();
		pq.pop();
		if(-d>dist1[u])
			continue;
		for(auto [v, nd] : adj[u]) {
			if(dist1[v]>nd*2+dist1[u]) {
				dist1[v]=nd*2+dist1[u];
				pq.push({-dist1[v], v});
			}
		}
	}
}

void di2() {
	priority_queue<Wolf> pq;
	dist2[0][0]=0;
	pq.push({0, 0, 0});
	while(!pq.empty()) {
		auto [u, d, f]=pq.top();
		pq.pop();
		if(d>dist2[u][f])
			continue;
		for(auto [v, nd] : adj[u]) {
			int nextD=(f?nd*4+dist2[u][f]:nd+dist2[u][f]);
			if(dist2[v][!f]>nextD) {
				dist2[v][!f]=nextD;
				pq.push({v, nextD, !f});
			}
		}
	}
}

void solve() {
	cin >> N >> M;
	for(int i=0; i<M; ++i) {
		int u, v, d;
		cin >> u >> v >> d, --u, --v;
		adj[u].push_back({v, d});
		adj[v].push_back({u, d});
	}
	for(int i=0; i<N; ++i) 
		dist1[i]=dist2[i][0]=dist2[i][1]=mx;
	di1();
	di2();
	for(int i=1; i<N; ++i)
		ans+=(dist1[i]<dist2[i][0]&&dist1[i]<dist2[i][1]);
	print(ans);
	/*
	print(dist1, N);
	for(int i=0; i<N; ++i)
		cout << dist2[i][0] << " ";
	cout << nl;
	for(int i=0; i<N; ++i)
		cout << dist2[i][1] << " ";
	cout << nl;
	*/
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
