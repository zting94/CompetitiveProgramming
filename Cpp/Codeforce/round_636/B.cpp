#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if ((n / 2) % 2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    long long sum = 0;
    for (int i = 1; i <= n / 2; ++i) {
        sum += (i * 2);
        cout << (i * 2) << " ";
    }
    for (int i = 1; i < n - 1; i += 2) {
        sum -= i;
        cout << i << " ";
    }
    cout << sum << "\n";
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
