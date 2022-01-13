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
const int mxN=201;
int N, K, M;

using matrix=vvi;

matrix operator*(matrix& a, matrix& b) {
	matrix c(N, vi(N));
	for(int i=0; i<N; ++i)
		for(int j=0; j<N; ++j)
			for(int k=0; k<N; ++k)
				c[i][j]|=a[i][k]&b[k][j];
	return c;
}

void solve() {
	cin >> N >> K >> M;
	matrix I(N, vi(N)), ans(N, vi(N));
	for(int i=0; i<N; ++i)
		I[i][i]=1;
	for(int i=0; i<N; ++i) {
		int a, b;
		cin >> a >> b, --a, --b;
		ans[i][a]=ans[i][b]=1;
	}
	while(K) {
		if(K&1)
			I=I*ans;
		ans=ans*ans;
		K/=2;
	}
	for(int i=0; i<M; ++i) {
		int a, b;
		cin >> a >> b, --a, --b;
		if(I[a][b])
			print("death");
		else
			print("life");
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
