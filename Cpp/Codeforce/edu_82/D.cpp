#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    ll N, M;
    cin >> N >> M;
    unordered_map<int, int> cnt;
    ll v;
    ll sum = 0;
    for (int i = 0; i < M; ++i) {
        cin >> v;
        cnt[(int)log2(v)]++;
        sum += v;
    }
    if (N > sum) {
        cout << -1 << '\n';
        return;
    }
    ll ans = 0;
    for (int i = 0; i < 60; ++i) {
        if (N & (1LL << i)) {
            if (cnt[i] > 0) {
                cnt[i]--;
            } else {
                while (i < 60 && cnt[i] == 0) {
                    ++i;
                    ++ans;
                }
                cnt[i]--;
                --i;
                continue;
            }
        }
        cnt[i + 1] += (cnt[i] / 2);
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
