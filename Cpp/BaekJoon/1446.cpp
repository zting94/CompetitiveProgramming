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

const int mxD=1e4+1;
vii adj[mxD];

void solve() {
	int N, D;
	cin >> N >> D;
	for(int i=0; i<N; ++i) {
		int s, e, d;
		cin >> s >> e >> d;
		if(e<=D)
			adj[s].push_back({e, d});
	}
	vi dist(D+1, 1e9);
	priority_queue<pii, vii, greater<pii>> pq;
	pq.push({0, 0});
	while(!pq.empty()) {
		auto [d, u]=pq.top();
		pq.pop();
		if(dist[u]<d)
			continue;
		dist[u]=d;
		for(auto [v, nd] : adj[u]) {
			if(nd+d<dist[v])
				pq.push({nd+d, v});
		}
		if(u+1<=D&&d+1<dist[u+1])
			pq.push({d+1, u+1});
	}
	print(dist[D]);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
