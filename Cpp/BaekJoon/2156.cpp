#include <bits/stdc++.h>

using namespace std;

int dp[3][10001];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    memset(dp, 0, sizeof(dp));
    for(auto& i : a) {
        cin >> i;
    }
    dp[1][0] = a[0];
    for(int i = 1; i < n; ++i) {
        dp[0][i] = max(dp[0][i - 1], max(dp[1][i - 1], dp[2][i - 1]));
        dp[1][i] = dp[0][i - 1] + a[i];
        dp[2][i] = dp[1][i - 1] + a[i];
    }
    cout << max(dp[0][n - 1], max(dp[1][n - 1], dp[2][n - 1])) << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}