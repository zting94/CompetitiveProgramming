#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    vector<int> cnt;
    int idx = 0;
    for (char c : s) {
        if (c != 'a' && c != 'b') {
            continue;
        }
        if (cnt.size() <= idx) {
            cnt.push_back(0);
        }
        if (c == 'a') {
            cnt[idx]++;
        } else if (c == 'b') {
            ++idx;
        }
    }
    long long ans = 1;
    for (int a : cnt) {
        ans *= (a + 1);
        ans %= M;
    }
    cout << ans - 1 << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}