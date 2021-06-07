#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int k = 3e2;

void solve() {
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (auto& i : arr) {
        cin >> i;
    }
    unordered_set<int> s;
    while (true) {
        bool can = true;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int v = abs(arr[i] - arr[j]);
                if (s.find(v) == s.end()) {
                    can = false;
                    arr.push_back(v);
                    s.insert(v);
                }
            }
        }
        n = arr.size();
        if (can) {
            cout << "YES\n";
            cout << s.size() << '\n';
            vector<int> ans(s.begin(), s.end());
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); ++i) {
                if (i > 0) {
                    cout << ' ';
                }
                cout << ans[i];
            }
            cout << '\n';
            return;
        } else if (s.size() > 300) {
            cout << "NO\n";
            break;
        }
    }
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
