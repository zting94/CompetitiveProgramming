#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, s;
    cin >> n >> s;
    vector<long long> arr(n);
    long long sum = 0;
    for (auto& i : arr) {
        cin >> i;
        sum += i;
    }
    if (sum < s) {
        cout << -1 << '\n';
        return;
    }
    sort(arr.rbegin(), arr.rend());
    sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        sum += (arr[i] - arr[n - 1]);
        if (sum >= s) {
            cout << arr[n - 1] << '\n';
            return;
        }
    }
    long long q = (s - sum) / n;
    long long ans = arr[n - 1] - q;
    long long mod = (s - sum) % n;
    if (mod) {
        --ans;
    }
    // cout << q << ' ' << mod << " " << sum << endl;
    cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
