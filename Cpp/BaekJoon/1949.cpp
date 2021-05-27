#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int N;
vector<int> arr;
vector<vector<int>> adj;
unordered_set<int> vis;

pair<int, int> dfs(int node, int parent) {
    if(vis.find(node) != vis.end()) {
        return {0, 0};
    }
    vis.insert(node);
    int pick = arr[node];
    int nopick = 0;
    for(int next : adj[node]) {
        if(next == parent) {
            continue;
        }
        auto v = dfs(next, node);
        pick += v.second;
        nopick += max(v.first, v.second);
    }
    return {pick, nopick};
}

void solve() {
    cin >> N;
    arr = vector<int>(N);
    adj = vector<vector<int>>(N);
    for(auto& i : arr) {
        cin >> i;
    }
    for(int i = 0; i < N - 1; ++i) {
        int from, to;
        cin >> from >> to;
        --from, --to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    auto ans = dfs(0, -1);
    cout << max(ans.first, ans.second) << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
