#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int mxN=1e3+1;
const int M=1e4+7;
int dp[mxN];

void solve() {
	int n;
	cin >> n;
	dp[0]=0;
	dp[1]=1;
	dp[2]=3;
	for(int i=3; i<=n; ++i) {
		dp[i]=(dp[i-1]+dp[i-2]*2)%M;
	}
	cout << dp[n] << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
