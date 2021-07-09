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
	int n;
	cin >> n;
	if(n<8) {
		print(-1);
		return;
	}
	vector<bool> b(n+1, true);
	vi p{2};
	for(int i=3; i*i<=n; i+=2) 
		if(b[i]) {
			for(int j=i+i; j<=n; j+=i)
				b[j]=false;
		}
	for(int i=3; i<=n; i+=2)
		if(b[i])
			p.push_back(i);
	bool flag=n&1;
	if(n&1)
		n-=5;
	else
		n-=4;
	for(int i=0; i<p.size(); ++i) {
		for(int j=0; j<p.size(); ++j) {
			if(p[i]+p[j]==n) {
				if(flag) {
					cout << "2 3 " << p[i] << ' ' << p[j] << '\n';
				} else {
					cout << "2 2 " << p[i] << ' ' << p[j] << '\n';
				}
				return;
			}
		}
	}
	assert(false);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
