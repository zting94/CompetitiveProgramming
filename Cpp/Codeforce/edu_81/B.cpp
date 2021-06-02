#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

// 0 1 0 0 1 0
// 1 0 1 2 1 2
// 3 2 3 4 3 4
// 5 4 5 6 5 6
// 7 6 7 8 7 8
// 9 8 9 10 9 10
// 11 10 11 12

void solve() {
    int N, X;
    string s;
    cin >> N >> X >> s;
    int zero = std::count_if(s.begin(), s.end(), [](auto& c) {
        return c == '0';
    });
    int total = 2 * zero - N;
    int cur = 0;
    int ans = 0;
    for(int i = 0; i < N; ++i) {
        if(total == 0) {
            if(cur == X) {
                cout << -1 << '\n';
                return;
            }
        } else if(abs(X - cur) % abs(total) == 0) {
            if((X - cur) / total >= 0) {
                ++ans;
            }
        }
    cur += (s[i] == '0' ? 1 : -1);
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
