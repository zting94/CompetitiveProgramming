#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

template<typename T>
void print(const vector<T>& v, char sp=' ') {
	for(int i=0; i<v.size(); ++i) {
		if(i>0)
			cout << sp;
		cout << v[i];
	}
	cout << '\n';
}

void print(int v) {
	cout << v << '\n';
}

template<typename T>
void read(vector<T>& v) {
	for(auto& x : v)
		cin >> x;
}

using matrix = vector<vector<ll>>;
const ll M=1e3;

matrix operator*(const matrix& a, const matrix& b) {
	assert(a.size()==b.size());
	int n=a.size();
	matrix c(n, vector<ll>(n));
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			for(int k=0; k<n; ++k) {
				c[i][j]+=(a[i][k]*b[k][j])%M;
			}
			c[i][j]%=M;
		}
	}
	return c;
}

matrix dp(const matrix& a, ll b) {
	if(b==1)
		return a;
	if(b&1) {
		auto v=dp(a, (b-1)/2);
		return a*v*v;
	}
	auto v=dp(a, b/2);
	return v*v;
}

void solve() {
	ll n, b;
	cin >> n >> b;
	matrix a(n, vector<ll>(n));
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			cin >> a[i][j];
			a[i][j]%=M;
		}
	}
	auto ret=dp(a, b);
	for(int i=0; i<n; ++i)
		print(ret[i]);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
