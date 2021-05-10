#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> jewel(n);
    multiset<int> bag;
    for(auto& a : jewel) {
        cin >> a.second >> a.first;
    }
    for(int i = 0; i < k; ++i) {
        int t;
        cin >> t;
        bag.insert(t);
    }
    sort(jewel.begin(), jewel.end(), [](auto& a, auto& b) {
        if(a.first == b.first) {
            return a.second > b.second;
        }
        return a.first > b.first;
    });
    long long ans = 0;
    int j = 0;
    for(auto& [value, weight] : jewel) {
        auto it = bag.lower_bound(weight);
        if(it == bag.end()) {
            continue;
        }
        ans += value;
        bag.erase(it);
    }
    cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}