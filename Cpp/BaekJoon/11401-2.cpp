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

const ll M=1e9+7;
int N, K;

ll ppow(ll a, ll b) {
	if(b==1)
		return a%M;
	if(b&1) {
		ll t=ppow(a, (b-1)/2)%M;
		return (((a*t)%M)*t)%M;
	}
	ll t=ppow(a, b/2)%M;
	return (t*t)%M;
}


void solve() {
	cin >> N >> K;
	ll a=1;
	for(int i=2; i<=N; ++i) {
		a*=i;
		a%=M;
	}
	ll b=1;
	for(int i=2; i<=K; ++i) {
		b*=i;
		b%=M;
	}
	ll c=1;
	for(int i=2; i<=N-K; ++i) {
		c*=i;
		c%=M;
	}
	print((a*ppow((b*c)%M, M-2))%M);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
