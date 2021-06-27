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

const int mxN=1e5+1;
vector<array<int, 4>> a;
int p[mxN];
int n;

class E {
public :
	E(int uu, int vv, int dd)
		: u(uu), v(vv), d(dd) {}
	int u, v;
	ll d;
};

bool operator<(const E& l, const E& r) {
	return l.d>r.d;
}

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
	cin >> n;
	for(int i=0; i<n; ++i)
		p[i]=i;
	a=vector<array<int, 4>>(n);
	for(int i=0; i<n; ++i) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		a[i][3]=i;
	}
	priority_queue<E> pq;
	auto ins=[&](int i) {
		sort(a.begin(), a.end(), [&](auto& l, auto& r) {
			return l[i]<r[i];
		});
		for(int j=0; j<n-1; ++j)
			pq.push(E(a[j][3], a[j+1][3], abs(a[j][i]-a[j+1][i])));
	};
	for(int i=0; i<3; ++i)
		ins(i);

	ll ans=0;
	while(!pq.empty()) {
		auto e=pq.top();
		pq.pop();
		if(same(e.u, e.v))
			continue;
		ans+=e.d;
		merge(e.u, e.v);
	}
	print(ans);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
