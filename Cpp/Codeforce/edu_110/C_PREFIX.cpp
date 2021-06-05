#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    string s;
    cin >> s;
    int N = s.size();
    vector<int> prefix[2][2];
    for (int a = 0; a < 2; ++a) {      // zeroCnt / oneCnt
        for (int b = 0; b < 2; ++b) {  // zeroOne / oneZero
            prefix[a][b].assign(N + 1, 0);
            for (int i = 0; i < N; ++i) {
                prefix[a][b][i + 1] =
                    prefix[a][b][i] + (i % 2 == b && s[i] == '0' + a);
            }
        }
    }

    auto exists = [&](int start, int end, int a, int b) {
        return prefix[a][b][end] > prefix[a][b][start];
    };

    auto isBeautiful = [&](int start, int end) {
        for (int a = 0; a < 2; ++a) {
            if (exists(start, end, a, 0) && exists(start, end, a, 1)) {
                return false;
            }
        }
        for (int b = 0; b < 2; ++b) {
            if (exists(start, end, 0, b) && exists(start, end, 1, b)) {
                return false;
            }
        }
        return true;
    };
    ll ans = 0;
    int left = 0, right = 0;
    for (int start = 0; start < N; ++start) {
        int l = start, r = N;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (isBeautiful(start, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        ans += l - start;
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
