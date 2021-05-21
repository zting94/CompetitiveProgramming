#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    unordered_set<char> us;
    for (char c : s) {
        us.insert(c);
    }
    if (us.size() == 1) {
        cout << -1 << '\n';
        return;
    }
    sort(s.begin(), s.end());
    cout << s << '\n';
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
