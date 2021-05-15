#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int mnA = 1e9, mnB = 1e9;
    for (auto& i : a) {
        cin >> i;
        mnA = min(mnA, i);
    }
    for (auto& i : b) {
        cin >> i;
        mnB = min(mnB, i);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += max(a[i] - mnA, b[i] - mnB);
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
