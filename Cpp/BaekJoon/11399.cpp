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
    sort(arr.begin(), arr.end());
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += arr[i];
        ans += sum;
    }
    cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
