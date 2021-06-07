#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    string t = "a";
    while (s.find(t) != string::npos) {
        if (t.back() != 'z') {
            t.back()++;
            continue;
        }
        int idx = t.size() - 2;
        int offset = 1;
        t.back() = 'a';
        while (idx >= 0 && offset > 0) {
            if (t[idx] != 'z') {
                t[idx]++;
                offset = 0;
            } else {
                t[idx] = 'a';
                --idx;
            }
        }
        if (offset > 0) {
            t = string(t.size() + 1, 'a');
        }
    }
    cout << t << '\n';
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
