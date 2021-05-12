#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    long long ans;
    {
        int da = min(n, a - x);
        int db = min(n - da, b - y);
        ans = (a - da) * 1LL * (b - db);
    }
    {
        int db = min(n, b - y);
        int da = min(n - db, a - x);
        ans = min(ans, (a - da) * 1LL * (b - db));
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