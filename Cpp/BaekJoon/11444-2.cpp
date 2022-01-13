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
const ll M=1e9+7;

using matrix=vvl;

matrix operator*(matrix& a, matrix& b) {
	matrix c(2, vl(2));
	for(int i=0; i<2; ++i)
		for(int j=0; j<2; ++j)
			for(int k=0; k<2; ++k)
				c[i][j]=(c[i][j]+a[i][k]*b[k][j])%M;
	return c;
}

void solve() {
	ll N;
	cin >> N, --N;
	matrix I{{1, 0}, {0, 1}}, F{{1, 1}, {1, 0}};
	while(N) {
		if(N&1)
			I=I*F;
		F=F*F;
		N/=2;
	}
	print(I[0][0]%M);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
