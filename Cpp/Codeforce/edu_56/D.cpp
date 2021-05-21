#include <bits/stdc++.h>

using namespace std;

const int mxN = 3e5 + 999;
int MOD = 998244353;
int N, M;
int cnt[2];
int col[mxN];
bool fail;
int pow2[mxN];
vector<int> adj[mxN];

void precalc() {
    pow2[0] = 1;
    for (int i = 1; i < mxN; ++i) {
        pow2[i] = (2LL * pow2[i - 1]) % MOD;
    }
}

void dfs(int u, int color) {
    col[u] = color;
    ++cnt[color];
    for (int to : adj[u]) {
        if (col[to] == -1) {
            dfs(to, 1 - color);
        }
        if (col[u] == col[to]) {
            fail = true;
        }
    }
}

void solve() {
    cin >> N >> M;
    memset(col, -1, sizeof(int) * N);
    for (int i = 0; i < N; ++i) {
        adj[i].clear();
    }
    int u, v;
    for (int i = 0; i < M; ++i) {
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fail = false;
    int ans = 1;
    for (int i = 0; i < N; ++i) {
        if (col[i] != -1) {
            continue;
        }
        cnt[0] = cnt[1] = 0;
        dfs(i, 0);
        if (fail) {
            cout << 0 << '\n';
            return;
        }
        int tmp = (pow2[cnt[0]] + pow2[cnt[1]]) % MOD;
        ans = (ans * 1LL * tmp) % MOD;
    }
    cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precalc();
    int testCase = 1;
    cin >> testCase;
    for (int t = 0; t < testCase; ++t) {
        solve();
    }

    return 0;
}
