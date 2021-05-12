#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto& a : arr) {
        cin >> a;
    }
    deque<pair<int, int>> dq;
    for (int i = 0; i < n; ++i) {
        while (!dq.empty() && dq.back().second >= arr[i]) {
            dq.pop_back();
        }
        if (!dq.empty() && dq.front().first < i - k + 1) {
            dq.pop_front();
        }
        dq.push_back({i, arr[i]});
        if (i > 0) {
            cout << " ";
        }
        cout << dq.front().second;
    }
    cout << "\n";
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}