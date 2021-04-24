#include <bits/stdc++.h>

using namespace std;

static const int V = 987654321;

void solve() {
    int x;
    cin >> x;
    vector<int> dp(x + 1, V);
    dp[1] = 0;
    for(int i = 2; i <= x; ++i) {
        int a = (i % 2 == 0) ? dp[i / 2] : V;
        int b = (i % 3 == 0) ? dp[i / 3] : V;
        dp[i] = min(min(a, b), dp[i - 1]) + 1;
    }
    cout << dp[x];
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}