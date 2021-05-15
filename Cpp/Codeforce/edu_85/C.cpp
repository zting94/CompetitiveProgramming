#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> h(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i] >> b[i];
    }
    long long ans = 0;
    long long mn = 1e18;
    for (int i = 0; i < n; ++i) {
        int next = (i + 1) % n;
        ans += max(0LL, h[next] - b[i]);
        mn = min(mn, min(h[next], b[i]));
    }
    ans += mn;
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
