#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int mxN = 1e5;
int N;
vector<pair<ll, ll>> arr;
vector<vector<int>> adj;
vector<pair<ll, ll>> dp;

// left, right
pair<ll, ll> dfs(int cur, int parent) {
    auto& result = dp[cur];
    result.first = result.second = 0;
    for (int child : adj[cur]) {
        if (child == parent) {
            continue;
        }
        dfs(child, cur);
        result.first +=
            max(dp[child].first + abs(arr[cur].first - arr[child].first),
                dp[child].second + abs(arr[cur].first - arr[child].second));
        result.second +=
            max(dp[child].first + abs(arr[cur].second - arr[child].first),
                dp[child].second + abs(arr[cur].second - arr[child].second));
    }
    return result;
}

void solve() {
    cin >> N;
    arr = vector<pair<ll, ll>>(N);
    dp = vector<pair<ll, ll>>(N + 1, {0, 0});
    adj = vector<vector<int>>(N);
    for (auto& i : arr) {
        cin >> i.first >> i.second;
    }
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    cout << max(dp[0].first, dp[0].second) << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCase = 1;
    cin >> testCase;
    for (int t = 0; t < testCase; ++t) {
        solve();
    }

    return 0;
}
