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

const int mxN=50, mxP=5e5;
int n;
vi a;
map<int, int> cnt;

void solve() {
	int zero=1;
	cin >> n;
	for(int i=0, v; i<n; ++i) {
		cin >> v;
		zero+=v==0;
		if(v) {
			a.push_back(v);
			cnt[v]++;
		}
	}
	sort(all(a));
	a.erase(unique(all(a)), a.end());
	vector<bool> p(mxP+1, 1);
	for(int i=4; i<=mxP; i+=2)
		p[i]=0;
	for(int i=3; i<=mxP; i+=2) {
		if(p[i]) {
			for(int j=i+i; j<=mxP; j+=i)
				p[j]=0;
		}
	}
	vl dp(mxP+1);
	dp[0]=1;
	for(int i : a) {
		for(int j=mxP; j>=0; --j) {
			for(int k=1; k<=cnt[i]; ++k) {
				if(j-k*i<0)
					break;
				dp[j]+=dp[j-k*i];
			}
		}
	}
	ll ans=0;
	for(int i=2; i<=mxP; ++i)
		if(p[i])
			ans+=dp[i];
	print(ans*zero);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
