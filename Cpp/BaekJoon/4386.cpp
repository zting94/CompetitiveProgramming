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
public :
	E(int uu, int vv, double dd)
		: u(uu), v(vv), d(dd) {}
	int u, v;
	double d;
};

bool operator<(const E& l, const E& r) {
	return l.d>r.d;
}

void solve() {
	int N;
	cin >> N;
	vector<pair<double, double>> a(N);
	for(auto& i : a)
		cin >> i.first >> i.second;
	vector<int> p(N);
	for(int i=0; i<N; ++i)
		p[i]=i;
	std::function<int(int)> find=[&](int a) {
		if(p[a]==a)
			return a;
		return p[a]=find(p[a]);
	};
	auto same=[&](int a, int b) {
		return find(a)==find(b);
	};
	auto merge=[&](int a, int b) {
		p[find(a)]=find(b);
	};
	priority_queue<E> pq;
	for(int i=0; i<N-1; ++i) {
		for(int j=i+1; j<N; ++j) {
			pq.push(E(i, j, sqrt(pow(abs(a[i].first-a[j].first),2)+pow(abs(a[i].second-a[j].second), 2))));
		}
	}

	double ans=0;
	while(!pq.empty()) {
		auto E=pq.top();
		pq.pop();
		if(same(E.u, E.v))
			continue;
		ans+=E.d;
		merge(E.u, E.v);
	}

	print(ans);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cout.precision(2);

    solve();

    return 0;
}
