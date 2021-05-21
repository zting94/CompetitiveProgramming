#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x;
    cin >> x;
    int ans = 0;
    for (int i = 7; i >= 2; --i) {
        if (x % i == 1) {
            continue;
        }
        ans += x / i;
        x %= i;
    }
    assert(x == 0);
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
