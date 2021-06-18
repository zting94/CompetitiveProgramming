#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

ll ppow(ll a, ll b, ll c) {
	if(b==1) {
		return a%c;
	}
	if(b&1) {
		ll t=ppow(a, (b-1)/2, c)%c;
		return (((a*t)%c)*t)%c;
	}
	ll t=ppow(a, b/2, c)%c;
	return (t*t)%c;
}

void solve() {
	ll a, b, c;
	cin >> a >> b >> c;
	cout << ppow(a, b, c) << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
