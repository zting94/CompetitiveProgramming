#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int inside(int v, int l, int r) {
    return l <= v && v <= r;
}

void solve() {
    int N, H, L, R;
    cin >> N >> H >> L >> R;
    vector<int> arr(N);
    for(auto& i : arr) {
        cin >> i;
    }
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
    int sum = 0;
    for(int i = 0; i < N; ++i) {
        sum += arr[i];
        for(int j = 0; j <= i; ++j) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + inside((sum - j) % H, L, R));
            if(j < N) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + inside((sum - j - 1) % H, L, R));
            }
        }
    }
    cout << *max_element(dp[N].begin(), dp[N].end()) << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
