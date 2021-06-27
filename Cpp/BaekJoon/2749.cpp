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

using matrix = vector<vector<ll>>;
const ll M=1e6;

matrix operator*(const matrix& a, const matrix& b) {
	matrix c(2, vector<ll>(2, 0));
	for(int i=0; i<2; ++i) {
		for(int j=0; j<2; ++j) {
			for(int k=0; k<2; ++k) {
				c[i][j]+=a[i][k]*b[k][j];
			}
			c[i][j]%=M;
		}
	}
	return c;
}

matrix fibo(const matrix& a, ll n) {
	if(n<=1) {
		return a;
	}
	if(n&1) {
		matrix b=fibo(a, (n-1)/2);
		return b*b*a;
	}
	matrix b=fibo(a, n/2);
	return b*b;
}

void solve() {
	matrix b(2, vector<ll>(2, 1));
	b[1][1]=0;
	ll n;
	cin >> n;
	if(n<=1) {
		print(n);
		return;
	}

	auto f=fibo(b, n-1);
	print(f[0][0]);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
