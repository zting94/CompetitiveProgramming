#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    set<int> a, b;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        if (a.find(v) == a.end()) {
            a.insert(v);
        } else {
            b.insert(v);
        }
    }
    int ans = 0;
    for (int i = 0; i <= 100; ++i) {
        if (a.find(i) == a.end()) {
            ans += i;
            break;
        }
    }
    for (int i = 0; i <= 100; ++i) {
        if (b.find(i) == b.end()) {
            ans += i;
            break;
        }
    }
    cout << ans << "\n";
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