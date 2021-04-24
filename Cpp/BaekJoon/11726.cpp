#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; ++i)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;

    cout << dp[n] << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}