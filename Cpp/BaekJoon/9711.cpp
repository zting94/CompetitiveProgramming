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
ll P, Q;

using matrix=vvl;

matrix operator*(matrix& a, matrix& b) {
	matrix c(2, vl(2));
	for(int i=0; i<2; ++i)
		for(int j=0; j<2; ++j)
			for(int k=0; k<2; ++k)
				c[i][j]=(c[i][j]+a[i][k]*b[k][j])%Q;
	return c;
}

ll solve() {
	cin >> P >> Q, --P;
	matrix I(2, vl(2)), F(2, vl(2));
	I[0][0]=I[1][1]=1;
	F[0][0]=F[0][1]=F[1][0]=1;
	while(P) {
		if(P&1)
			I=I*F;
		F=F*F;
		P/=2;
	}
	return I[0][0]%Q;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int tt;
	cin >> tt;
	for(int i=1; i<=tt; ++i)
		cout << "Case #" << i << ": " << solve() << nl;

    return 0;
}
