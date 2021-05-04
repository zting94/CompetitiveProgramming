#include <bits/stdc++.h>

using namespace std;

int n;
int ans;
int arr[501][501];
int dp[501][501];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int dfs(int r, int c, int v) {
    if(r < 0 || c < 0 || n <= r || n <= c || arr[r][c] <= v) {
        return 0;
    }
    int& ret = dp[r][c];
    if(ret != -1) {
        return ret;
    }
    ret = 1;
    for(int i = 0; i < 4; ++i) {
        ret = max(ret, dfs(r + dr[i], c + dc[i], arr[r][c]) + 1);
    }

    return ret;
}

void solve() {
    cin >> n;
    for(int r = 0; r < n; ++r) {
        for(int c = 0; c < n; ++c) {
            cin >> arr[r][c];
        }
    }
    memset(dp, -1, sizeof(dp));
    ans = 0;
    for(int r = 0; r < n; ++r) {
        for(int c = 0; c < n; ++c) {
            ans = max(ans, dfs(r, c, INT_MIN));
        }
    }
    cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}