#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    string s;
    cin >> s;
    s += 'R';
    int ans = 1;
    int cur = 0;
    for(int i = 0; i < s.size(); ++i) {
        ++cur;
        if(s[i] == 'R') {
            ans = max(ans, cur);
            cur = 0;
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
