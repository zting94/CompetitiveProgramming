#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int n;
	cin >> n;
	vector<ll> dp(n+4, 0);
	dp[1]=dp[2]=dp[3]=1;
	for(int i=4; i<=n; ++i) {
		dp[i]=dp[i-3]+dp[i-2];
	}
	cout << dp[n] << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int tt;
	cin >> tt;
	while(tt--) {
    	solve();
	}

    return 0;
}
