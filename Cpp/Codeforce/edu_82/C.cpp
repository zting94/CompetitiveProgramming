#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    string ans;
    int idx = -1;
    unordered_set<char> used;
    for (char c : s) {
        if (idx == -1) {
            ans += c;
            used.insert(c);
            idx = 0;
            continue;
        }
        if (used.find(c) != used.end()) {
            if (idx < ans.size() && ans[idx + 1] == c) {
                ++idx;
            } else if (idx > 0 && ans[idx - 1] == c) {
                --idx;
            } else {
                cout << "NO\n";
                return;
            }
            continue;
        }
        if (idx != 0 && idx != ans.size() - 1) {
            cout << "NO\n";
            return;
        }
        if (idx == ans.size() - 1) {
            ans += c;
            ++idx;
        } else {
            ans = c + ans;
        }
        used.insert(c);
    }
    for (int i = 0; i < 26; ++i) {
        char c = 'a' + i;
        if (used.find(c) == used.end()) {
            ans += c;
        }
    }
    cout << "YES\n";
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
