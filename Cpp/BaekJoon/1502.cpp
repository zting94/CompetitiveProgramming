#include <bits/stdc++.h>

using namespace std;

int cache[501][501];
int n, m;
const int dr[4] = {-1, 0, 0, 1};
const int dc[4] = {0, -1, 1, 0};

bool isValid(int r, int c) {
    return 0 <= r && 0 <= c && r < n && c < m;
}

int dfs(const vector<vector<int>>& arr, int r, int c, int prev) {
    if(!isValid(r, c) || arr[r][c] >= prev) {
        return 0;
    }
    int& result = cache[r][c];
    if(result != -1) {
        return result;
    }
    if(r == n - 1 && c == m - 1) {
        return result = arr[r][c] < prev ? 1 : 0;
    }
    result = 0;
    for(int i = 0; i < 4; ++i) {
        result += dfs(arr, r + dr[i], c + dc[i], arr[r][c]);
    }
    return result;
}

void solve() {
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    memset(cache, -1, sizeof(cache));
    for(int r = 0; r < n; ++r) {
        for(int c = 0; c < m; ++c) {
            cin >> arr[r][c];
        }
    }
    dfs(arr, 0, 0, INT_MAX);
    cout << max(0, cache[0][0]) << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}