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

void solve() {
	int n;
	cin >> n;
	vector<int> pp(n+1);
	for(int i=2; i<=n; ++i)
		pp[i]=(i&1)?i:2;
	for(int i=3; i<=n; i+=2) 
		if(pp[i]==i) 
			for(int j=i*2; j<=n; j+=i)
				pp[j]=i;
	vector<int> p;
	for(int i=2; i<=n; ++i)
		if(pp[i]==i)
			p.push_back(i);
	int a, b, minDiff=1e9;
	for(int i=0; i<p.size(); ++i) {
		int j=lower_bound(p.begin(), p.end(), n-p[i])-p.begin();
		if((j!=p.size())&&(p[i]+p[j]==n)&&(abs(p[i]-p[j])<minDiff)) {
			a=min(p[i], p[j]);
			b=max(p[i], p[j]);
			minDiff=abs(p[i]-p[j]);
		}
	}
	cout << a << ' ' << b << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int tt;
	cin >> tt;
	while(tt--)
    	solve();

    return 0;
}
