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
#define fi first
#define sn second


template<typename T, typename V>
void print(const pair<T, V>& p, string sp=" ") {
	cout << p.fi << sp << p.sn << nl;
}

template<typename T>
void print(const vector<T>& v, string sp=" ") {
	for(int i=0; i<v.size(); ++i) {
		if(i>0)
			cout << sp;
		cout << v[i];
	}
	cout << '\n';
}

template<typename T>
void print(const vector<vector<T>>& v, string sp=" ") {
	for(auto& vv : v)
		print(vv, sp);
}

template<typename T>
void print(T v) {
	cout << v << '\n';
}

template<typename T>
void print(T v[], int sz, string sp=" ") {
	for(int i=0; i<sz; ++i) {
		if(i>0)
			cout << sp;
		cout << v[i];
	}
	cout << '\n';
}

template<typename T>
void print(T* A, int N, int M, string sp=" ") {
	for(int i=0; i<N; ++i)
		print(A[i], M, sp);
}

template<typename T, typename V>
istream& operator>>(istream& o, pair<T, V>& v) {
	o >> v.fi >> v.sn;
	return o;
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

template<typename T>
void read(T* A, int N, int M) {
	for(int i=0; i<N; ++i)
		read(A[i], M);
}

const int dx[4]={-1, 0, 1, 0}, dy[4]={0, -1, 0, 1};

void solve() {
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
