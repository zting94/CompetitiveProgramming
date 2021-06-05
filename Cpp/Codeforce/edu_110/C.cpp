#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    string s;
    cin >> s;
    int N = s.size();
    for (int i = 0; i < N; i += 2) {
        if (s[i] == '0') {
            s[i] = '1';
        } else if (s[i] == '1') {
            s[i] = '0';
        }
    }
    ll ans = 0;
    int left = 0, right = 0;
    int zero = 0, one = 0;
    while (right < N) {
        if (s[right] == '1') {
            ++one;
        } else if (s[right] == '0') {
            ++zero;
        }
        while (zero > 0 && one > 0) {
            if (s[left] == '1') {
                --one;
            } else if (s[left] == '0') {
                --zero;
            }
            ++left;
        }
        ans += right - left + 1;
        ++right;
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
