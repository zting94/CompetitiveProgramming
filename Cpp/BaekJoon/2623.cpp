#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int mxN = 1e3;
int N, M;
unordered_set<int> adj[mxN];
int cnt[mxN];

void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int sz;
        cin >> sz;
        vector<int> edge(sz);
        for (auto& e : edge) {
            cin >> e;
            --e;
        }
        for (int j = 0; j < sz - 1; ++j) {
            if (adj[edge[j]].find(edge[j + 1]) == adj[edge[j]].end()) {
                cnt[edge[j + 1]]++;
                adj[edge[j]].insert(edge[j + 1]);
            }
        }
    }
    queue<int> q;
    vector<int> ans;
    unordered_set<int> v;
    for (int i = 0; i < N; ++i) {
        if (cnt[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty() && ans.size() < N) {
        int u = q.front();
        q.pop();
        if (v.find(u) != v.end()) {
            continue;
        }
        ans.push_back(u + 1);
        v.insert(u);

        for (int next : adj[u]) {
            cnt[next]--;
            if (cnt[next] == 0) {
                q.push(next);
            }
        }
    }
    if (ans.size() < N) {
        cout << 0 << '\n';
        return;
    }
    for (auto& u : ans) {
        cout << u << '\n';
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
