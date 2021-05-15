#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long x, y, n;
    cin >> x >> y >> n;
    int v = n / x + 1;
    for (int i = v; i >= 1; --i) {
        long long ans = x * i + y;
        if (ans <= n) {
            cout << ans << '\n';
            return;
        }
    }
    cout << y << '\n';
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
