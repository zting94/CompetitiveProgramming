#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e9;
using ll = long long;
using ull = unsigned long long;

void solve() {
    int N;
    cin >> N;
    int v = N % 11;
    if (N >= 111 * v) {
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