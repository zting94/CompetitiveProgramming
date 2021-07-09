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

const int M=1e9+7;

void solve() {
	int n;
	cin >> n;
	vi dp(n+2, 0);
	dp[2]=1;
	for(int i=3; i<=n; ++i) 
		dp[i]=(dp[i-1]+2LL*dp[i-2])%M;
	print(dp[n]);
	/*
	vector<int> a{1, 5}, b, p, pall;
	print(a);
	while(a.back()<=1e8) {
		for(int i : a) {
			for(int j : {1, 5}) {
				int t=i*10+j;
				if(t%15==0)
					p.push_back(t);
				b.push_back(t);
			}
		}
		print(p);
		cout << "Size : " << p.size() << endl;
		pall.insert(pall.end(), p.begin(), p.end());
		cout << endl;
		a=b;
		p.clear();
		b.clear();
	}
	*/
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
