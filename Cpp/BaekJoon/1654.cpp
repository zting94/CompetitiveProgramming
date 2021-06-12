#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	ll k, n;
	cin >> k >> n;
	vector<ll> a(k);
	for(auto& i : a)
		cin >> i;
	int ans=1;
	ll l=1, r=INT_MAX;
	while(l<=r) {
		ll m=(l+r)/2;
		ll cur=0;
		for(auto i : a) {
			cur+=i/m;
		}
		if(cur>=n) {
			ans=m;
			l=m+1;
		} else {
			r=m-1;
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
