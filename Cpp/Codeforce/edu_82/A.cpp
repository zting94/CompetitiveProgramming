#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int left = n, right = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            left = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '1') {
            right = i;
            break;
        }
    }
    int ans = 0;
    for (int i = left; i <= right; ++i) {
        if (s[i] == '0') {
            ++ans;
        }
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
