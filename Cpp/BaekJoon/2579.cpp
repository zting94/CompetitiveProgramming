#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> s(n + 4, 0);
    vector<int> dp(n + 4, 0);
    for(int i = 0; i < n; ++i)
        cin >> s[i];
    dp[0] = s[0];
    dp[1] = s[0] + s[1];
    dp[2] = max(s[0], s[1]) + s[2];
    for(int i = 3; i < n; ++i) {
        dp[i] = max(dp[i - 2] + s[i], dp[i - 3] + s[i - 1] + s[i]);
    }
    cout << dp[n - 1] << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}