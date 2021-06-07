#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int mxN = 1e5;
int arr[mxN];
bool v[mxN];
bool done[mxN];
int cnt;

void dfs(int u) {
    v[u] = true;
    int next = arr[u];
    if (!v[next]) {
        dfs(next);
    } else if (!done[next]) {
        for (int i = next; i != u; i = arr[i]) {
            ++cnt;
        }
        ++cnt;
    }
    done[u] = true;
}

void solve() {
    int N;
    cin >> N;
    cnt = 0;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        --arr[i];
        v[i] = done[i] = false;
    }
    for (int i = 0; i < N; ++i) {
        if (!v[i]) {
            dfs(i);
        }
    }

    cout << N - cnt << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}