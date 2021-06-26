#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

template<typename T>
void print(const vector<vector<T>>& v, char sp=' ') {
	int n=v.size();
	if(n==0)
		return;
	int m=v[0].size();
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			if(j>0)
				cout << sp;
			cout << v[i][j];
		}
		cout << '\n';
	}
}

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
void print(T v) {
	cout << v << '\n';
}

template<typename T>
void read(vector<vector<T>>& v) {
	for(auto& a : v)
		for(auto& i : a)
			cin >> i;
}

template<typename T>
void read(vector<T>& v) {
	for(auto& x : v)
		cin >> x;
}

const int M=1e9+7;
ll n, s, m;

ll ppow(ll a, ll b) {
	ll ret=1;
	while(b) {
		if(b&1)
			ret*=a;
		a*=a;
		ret%=M;
		a%=M;
		b/=2;
	}
	return ret%M;
}

void solve() {
	n=s=0;
	cin >> m;
	ll ans=0;
	for(int i=0; i<m; ++i) {
		ll ss, nn;
		cin >> nn >> ss;
		//Fermat
		//a^p MOD p = a(p is prime, a!=0)
		ans+=((ss%M)*ppow(nn, M-2))%M;
	}
	print(ans%M);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
