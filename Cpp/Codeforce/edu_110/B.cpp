#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (auto& i : arr) {
        cin >> i;
    }
    sort(arr.rbegin(), arr.rend());
    ll ans = 0;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (__gcd(arr[i], arr[j] * 2) > 1 ||
                __gcd(arr[i] * 2, arr[j]) > 1) {
                ++ans;
            }
        }
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
