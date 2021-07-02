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
void read(vector<T>& v) {
	for(auto& x : v)
		cin >> x;
}

template<typename T>
void read(vector<vector<T>>& v) {
	for(auto& a : v)
		read(a);
}

const int mxN=4e6+1;
const ull M=1e9+7;
ull f[mxN];
int N, K;

ull ppow(ull a, ull b) {
	assert(a%M>=0);
	if(b==1)
		return a%M;
	if(b&1) {
		ull t=ppow(a, (b-1)/2)%M;
		assert(t>=0);
		return (((a*t)%M)*t)%M;
	}
	ull t=ppow(a, b/2)%M;
	assert(t>=0);
	return (t*t)%M;
}


void solve() {
	cin >> N >> K;
	f[0]=f[1]=1;
	for(ll i=2; i<mxN; ++i) {
		f[i]=(f[i-1]*i)%M;
		assert(f[i]>=0);
	}
	// ans = N!/(N-K)!K!
	print((f[N]*ppow((f[N-K]*f[K])%M, M-2))%M);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
