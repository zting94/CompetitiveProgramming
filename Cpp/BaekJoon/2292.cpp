#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	ll n;
	cin >> n;
	if(n==1) {
		cout << 1 << '\n';
		return;
	}
	--n;
	for(int i=1; i<=INT_MAX; ++i) {
		n-=6*i;
		if(n<=0) {
			cout << (i+1) << '\n';
			return;
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
