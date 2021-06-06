#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int N, K1, K2, W, B;
    cin >> N >> K1 >> K2;
    cin >> W >> B;
    if ((K1 + K2 >= 2 * W) && ((N - K1) + (N - K2) >= 2 * B)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
