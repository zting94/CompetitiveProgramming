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

ll N, L;

ll Sum(int i) {
	return (i * 1LL * (i+1)) / 2;
}

ll Sum(int i, int sz) {
	return Sum(i+sz-1)-Sum(i-1);
}

bool chk(int sz) {
	ll l = 0, r = 1e9+7;
	while(l<r) {
		ll m=(l+r)/2;
		ll s=Sum(m, sz);
		if(s==N) {
			for(ll i=m; i<m+sz; ++i)
				cout << i << ' ';
			cout << '\n';
			return true;
		}
		if(s>N)
			r=m;
		else
			l=m+1;
	}
	return false;
}

void solve() {
	cin >> N >> L;
	for(int i=L; i<=100; ++i) 
		if(chk(i))
			return;
	print(-1);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
