#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    bool used[51][101];
    int cnt[101];
    memset(used, 0, sizeof(used));
    memset(cnt, 0, sizeof(cnt));
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int sum = a[i] + a[j];
            if (!used[i][sum] && !used[j][sum]) {
                ++cnt[sum];
                used[i][sum] = used[j][sum] = true;
                ans = max(ans, cnt[sum]);
            }
        }
    }
    cout << ans << '\n';
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
