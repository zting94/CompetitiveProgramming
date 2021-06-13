#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int n;
	ll m;
	cin >> n >> m;
	vector<ll> a(n);
	for(auto& i : a)
		cin >> i;
	ll ans=0;
	ll l=0, r=LONG_MAX;
	while(l+1<r) {
		ll h=(l+r)/2;
		ll cur=0;
		for(auto i : a) {
			cur+=max(0LL,i-h);
		}
		if(cur>=m) {
			ans=h;
			l=h;
		} else {
			r=h;
		}
	}
	cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
