#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;
    int v = 1;
    for (int i = 2;; i *= 2) {
        v += i;
        if (N % v == 0) {
            cout << N / v << "\n";
            return;
        }
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
