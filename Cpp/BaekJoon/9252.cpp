#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int mxN = 1e3 + 2;
string s, t;
int cache[mxN][mxN];

int dp(int i, int j) {
    if (i + 1 == s.size() || j + 1 == t.size()) {
        return 0;
    }
    int& ret = cache[i + 1][j + 1];
    if (ret != -1) {
        return ret;
    }
    ret = (s[i + 1] == t[j + 1]) + dp(i + 1, j + 1);
    ret = max(ret, dp(i + 1, j));
    ret = max(ret, dp(i, j + 1));
    return ret;
}

void find(int i, int j, int& remain) {
    if (i == s.size() || j == t.size() || remain <= 0 || cache[i][j] < remain) {
        return;
    }
    if (s[i] == t[j]) {
        if (cache[i][j] == remain) {
            cout << s[i];
            --remain;
        }
        find(i + 1, j + 1, remain);
    }
    find(i + 1, j, remain);
    find(i, j + 1, remain);
}

void solve() {
    cin >> s >> t;
    memset(cache, -1, sizeof(cache));

    int ans = dp(-1, -1);
    cout << ans << '\n';
    if (ans == 0) {
        return;
    }

    find(0, 0, ans);

    cout << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
