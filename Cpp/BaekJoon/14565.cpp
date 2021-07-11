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

ll EE(ll a, ll b) {
	ll r1=a, r2=b, s1=1, s2=0, t1=0, t2=1;
	while(r2) {
		ll q=r1/r2;
		ll r=r1%r2;
		r1=r2;
		r2=r;
		ll s=s1-q*s2;
		s1=s2;
		s2=s;
		ll t=t1-q*t2;
		t1=t2;
		t2=t;
	}
	return t1;
}

void solve() {
	ll N, A;
	cin >> N >> A;
	ll P=(N-A+N)%N;
	if(__gcd(N, A)!=1) {
		cout << P << " -1\n";
		return;
	}
	ll M=EE(N, A);
	while(M<0)
		M+=N;
	cout << P << ' ' << (M+N)%N << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
