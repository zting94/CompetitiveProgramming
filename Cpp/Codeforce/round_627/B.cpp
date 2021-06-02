#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int N;
    cin >> N;
    vector<int> arr(N);
    unordered_map<int, vector<int>> mp;
    bool can = false;
    for(int i = 0; i < N; ++i) {
        cin >> arr[i];
        mp[arr[i]].push_back(i);
        for(auto v : mp[arr[i]]) {
            if(i - v > 1) {
                can = true;
            }
        }
    }
    if(can) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
