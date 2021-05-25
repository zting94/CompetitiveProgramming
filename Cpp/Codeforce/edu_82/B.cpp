#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    ll n, g, b;
    cin >> n >> g >> b;
    if ((n + 1) / 2 <= g) {
        cout << n << '\n';
        return;
    }
    ll half = (n + 1) / 2;
    ll ans = (half / g) * (g + b);
    if (half % g != 0) {
        ans += (half % g);
    } else {
        ans -= b;
    }
    cout << max(ans, n) << '\n';
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
