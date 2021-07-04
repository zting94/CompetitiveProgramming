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

const ll M=987654321;

void solve() {
	ll n;
	cin >> n;
	vector<bool> a(n+1, true);
	vector<int> p{2};
	for(int i=4; i<=n; i+=2)
		a[i]=false;
	for(int i=3; i<=n; i+=2) {
		if(a[i]) {
			p.push_back(i);
			for(int j=i*2; j<=n; j+=i)
				a[j]=false;
		}
	}
	ll lcm=1;
	for(int i=0; i<p.size()&&p[i]<=n; ++i) {
		ll pp=p[i];
		while(pp*p[i]<=n)
			pp=pp*p[i];
		lcm*=pp;
		lcm%=M;
	}	
	print(lcm);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
