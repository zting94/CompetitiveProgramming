#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int N;
    cin >> N;
    vector<ll> arr(N);
    for (auto& i : arr) {
        cin >> i;
    }
    sort(arr.begin(), arr.end());
    vector<ll> ans(3);
    ll diff = LONG_MAX;
    auto set = [&](int i, int j, int k, ll curDiff) {
        ans[0] = arr[i];
        ans[1] = arr[j];
        ans[2] = arr[k];
        diff = curDiff;
    };
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            ll cur = arr[i] + arr[j];
            int idx = lower_bound(arr.begin(), arr.end(), -cur) - arr.begin();
            if (idx != i && idx != j && idx < N) {
                ll curDiff = abs(cur + arr[idx]);
                if (curDiff < diff) {
                    set(i, j, idx, curDiff);
                }
            }
            if (idx - 1 != i && idx - 1 != j && idx > 0) {
                ll curDiff = abs(cur + arr[idx - 1]);
                if (curDiff < diff) {
                    set(i, j, idx - 1, curDiff);
                }
            }
            if (idx + 1 != i && idx + 1 != j && idx + 1 < N) {
                ll curDiff = abs(cur + arr[idx + 1]);
                if (curDiff < diff) {
                    set(i, j, idx + 1, curDiff);
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
