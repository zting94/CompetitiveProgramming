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

void solve() {
	int n, c;
	cin >> n >> c;
	vl f(21);
	f[0]=1;
	for(int i=1; i<21; ++i)
		f[i]=i*f[i-1];
	vi a(n);
	vector<bool> chk(n+1, false);
	if(c==1) {
		ll k;
		cin >> k;
		ll ans=0;
		for(int i=0; i<n; ++i) {
			for(int j=1; j<=n; ++j) {
				if(chk[j])
					continue;
				if(f[n-i-1]<k)
					k-=f[n-i-1];
				else {
					a[i]=j;
					chk[j]=true;
					break;
				}
			}
		}
		print(a);
	} else {
		read(a);
		ll ans=1;
		for(int i=0; i<n; ++i) {
			for(int j=1; j<a[i]; ++j) {
				if(!chk[j])
					ans+=f[n-i-1];
			}
			chk[a[i]]=true;
		}
		print(ans);
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
