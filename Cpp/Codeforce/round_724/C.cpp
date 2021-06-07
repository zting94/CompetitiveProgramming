#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int d = 0, k = 0;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            cout << ' ';
        }
        d += (s[i] == 'D');
        k += (s[i] == 'K');
        int g = __gcd(d, k);
        cout << ++mp[{d / g, k / g}];
    }
    cout << '\n';
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
