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

const int mxN=1e6;

void solve() {
	int n;
	cin >> n;
	vi a(n), p;
	read(a);
	vector<bool> b(mxN+1, true);
	for(int i=3; i*i<=mxN; i+=2)
		if(b[i]) {
			for(int j=i*i; j<=mxN; j+=i)
				b[j]=false;
		}
	p.push_back(2);
	for(int i=3; i<=mxN; i+=2)
		if(b[i])
			p.push_back(i);
	vi mp(p.size()+1);
	vvi nums(n+1, vi(p.size()+1, 0));
	for(int i=0; i<n; ++i) {
		int t=a[i];
		for(int j=0; j<p.size(); ++j) {
			if(t<p[j])
				break;
			while(t%p[j]==0) {
				mp[j]++;
				nums[i][j]++;
				t/=p[j];
			}
		}
	}
	ll ans1=1, ans2=0;
	for(int i=0; i<p.size(); ++i) {
		for(int j=0; j<n; ++j) {
			if(mp[i]/n>nums[j][i])
				ans2+=mp[i]/n-nums[j][i];
		}
		ans1*=pow(p[i], mp[i]/n);
	}
	cout << ans1 << ' ' << ans2 << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
    solve();

    return 0;
}

