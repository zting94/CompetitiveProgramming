#include <bits/stdc++.h>

using namespace std;

int dp[17][(1 << 17) + 1];
int n;

int dfs(const vector<vector<int>>& dist, int idx, int mask) {
    if(mask == (1 << n) - 1) {
        return dist[idx][0];
    }
    int& result = dp[idx][mask];
    if(result != -1) {
        return result;
    }
    result = 1e9 + 7;
    for(int i = 0; i < n; ++i) {
        if((mask & (1 << i)) || dist[idx][i] == 0) {
            continue;
        }
        int nextDist = dfs(dist, i, mask | (1 << i));
        if(nextDist > 0) {
            result = min(result, nextDist + dist[idx][i]);
        }
    }
    return result;
}

void solve() {
    cin >> n;
    vector<vector<int>> dist(n, vector<int>(n, 0));
    for(int r = 0; r < n; ++r) {
        for(int c = 0; c < n; ++c) {
            cin >> dist[r][c];
        }
    }
    cout << dfs(dist, 0, 1) << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));
    solve();

    return 0;
}