#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (auto& a : arr) {
        cin >> a;
    }
    long long sum = 0;
    sort(arr.rbegin(), arr.rend());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        if (sum < (long long)x * (ans + 1)) {
            break;
        }
        ++ans;
    }
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
