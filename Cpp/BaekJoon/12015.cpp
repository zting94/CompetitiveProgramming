#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& in : arr) {
        cin >> in;
    }
    vector<int> lis{-1};
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (lis.back() < arr[i]) {
            lis.push_back(arr[i]);
            ans = lis.size() - 1;
        } else {
            auto k = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
            lis[k] = arr[i];
        }
    }

    cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}