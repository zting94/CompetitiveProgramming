#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> ans(n);
    vector<int> zero, one;
    for (int i = 0; i < n; ++i) {
        int seq = zero.size() + one.size();
        if (s[i] == '0') {
            if (one.empty()) {
                zero.push_back(seq);
            } else {
                seq = one.back();
                one.pop_back();
                zero.push_back(seq);
            }
        } else {
            if (zero.empty()) {
                one.push_back(seq);
            } else {
                seq = zero.back();
                zero.pop_back();
                one.push_back(seq);
            }
        }
        ans[i] = seq + 1;
    }
    cout << zero.size() + one.size() << '\n';
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            cout << ' ';
        }
        cout << ans[i];
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
