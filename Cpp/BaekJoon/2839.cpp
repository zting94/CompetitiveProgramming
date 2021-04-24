#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if(n == 3 || n == 5) {
        cout << 1;
        return;
    }
    if(n < 5) {
        cout << -1;
        return;
    }
    vector<int> dp(n + 1, 1234567);
    dp[3] = dp[5] = 1;
    for(int i = 6; i <= n; ++i) {
        dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);
    }

    if(dp[n] >= 1234567)
        cout << -1;
    else
        cout << dp[n];
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}