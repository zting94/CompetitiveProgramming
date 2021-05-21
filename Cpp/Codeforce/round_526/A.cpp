#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& i : arr) {
        cin >> i;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += 4 * arr[i] * i;
    }
    cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
