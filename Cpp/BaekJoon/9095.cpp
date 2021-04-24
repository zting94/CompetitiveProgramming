#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if(n == 1) {cout << 1 << '\n'; return;}
    if(n == 2) {cout << 2 << '\n'; return;}
    if(n == 3) {cout << 4 << '\n'; return;}
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    cout << dp[n] << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
        solve();

    return 0;
}