#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; ++i) {
        if (a[i + 1] - a[i] > 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
