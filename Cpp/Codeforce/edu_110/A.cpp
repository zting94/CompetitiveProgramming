#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int mx1 = max(a, b);
    int mn1 = min(a, b);
    int mx2 = max(c, d);
    int mn2 = min(c, d);
    if (mx1 < mn2 || mx2 < mn1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
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
