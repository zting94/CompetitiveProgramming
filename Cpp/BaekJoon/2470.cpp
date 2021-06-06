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
    int x, y;
    int diff = INT_MAX;
    for (int i = 0; i < N; ++i) {
        int idx = lower_bound(arr.begin(), arr.end(), -arr[i]) - arr.begin();
        if (i != idx && idx < N) {
            int curDiff = abs(arr[i] + arr[idx]);
            if (curDiff < diff) {
                x = arr[i];
                y = arr[idx];
                diff = curDiff;
            }
        }
        if (idx > 0 && idx - 1 != i) {
            int curDiff = abs(arr[i] + arr[idx - 1]);
            if (curDiff < diff) {
                x = arr[i];
                y = arr[idx - 1];
                diff = curDiff;
            }
        }
        if (idx + 1 < N && idx + 1 != i) {
            int curDiff = abs(arr[i] + arr[idx + 1]);
            if (curDiff < diff) {
                x = arr[i];
                y = arr[idx + 1];
                diff = curDiff;
            }
        }
    }
    if (x > y) {
        swap(x, y);
    }
    cout << x << ' ' << y << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
