#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    int ans = 0;
    while (n > 1) {
        if (n % 3) {
            cout << "-1\n";
            return;
        }
        if (n % 6 == 0) {
            n /= 6;
        } else {
            n *= 2;
        }
        ++ans;
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
