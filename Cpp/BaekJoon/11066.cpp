#include <bits/stdc++.h>

using namespace std;

int cache[501][501];
int arr[501];

int dp(int left, int right) {
    if (left > right) {
        return 0;
    }
    if (left == right) {
        return arr[left];
    }
    int& ret = cache[left][right];
    if (ret != -1) {
        return ret;
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    memset(cache, -1, sizeof(cache));
    cout << dp(0, n - 1) << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}