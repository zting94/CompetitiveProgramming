#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

template<typename T>
void print(const vector<vector<T>>& v, char sp=' ') {
	int n=v.size();
	if(n==0)
		return;
	int m=v[0].size();
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			if(j>0)
				cout << sp;
			cout << v[i][j];
		}
		cout << '\n';
	}
}

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
void print(T v) {
	cout << v << '\n';
}

template<typename T>
void read(vector<vector<T>>& v) {
	for(auto& a : v)
		for(auto& i : a)
			cin >> i;
}

template<typename T>
void read(vector<T>& v) {
	for(auto& x : v)
		cin >> x;
}

class E {
public:
	E(int uu, int vv, int dd)
		:u(uu), v(vv), d(dd) {}
	int u, v, d;
};

bool operator<(const E& l, const E& r) {
	return l.d>r.d;
}

const int mxN=1e5;
int p[mxN+1];
int n, m;

int find(int a) {
	if(p[a]==a)
		return a;
	return p[a]=find(p[a]);
}

void merge(int a, int b) {
	p[find(a)]=find(b);
}

bool same(int a, int b) {
	return find(a)==find(b);
}

void solve() {
	cin >> n >> m;
	for(int i=1; i<=n; ++i)
		p[i]=i;
	int ans=0, mxD=0;
	priority_queue<E> pq;
	for(int i=0; i<m; ++i) {
		int u, v, d;
		cin >> u >> v >> d;
		pq.push(E(u, v, d));
	}
	while(!pq.empty()) {
		auto e=pq.top();
		pq.pop();
		if(same(e.u, e.v))
			continue;
		merge(e.u, e.v);
		ans+=e.d;
		mxD=max(mxD, e.d);
	}
	print(ans-mxD);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
