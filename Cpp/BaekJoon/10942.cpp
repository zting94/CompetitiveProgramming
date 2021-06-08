#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int mxN = 2e3 + 1;
int cache[mxN][mxN];
int N, M;
int arr[mxN];

int dp(int l, int r) {
    if (l >= r) {
        return 1;
    }
    int& ret = cache[l][r];
    if (ret != -1) {
        return ret;
    }
    ret = (arr[l] == arr[r]);
    return ret &= dp(l + 1, r - 1);
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < N; ++i) {
        memset(cache[i], -1, sizeof(int) * N);
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;

        cout << dp(l, r) << '\n';
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
