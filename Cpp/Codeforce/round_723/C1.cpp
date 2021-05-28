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
    priority_queue<int, vector<int>, greater<int>> pq;
    ll sum = 0;
    int ans = 0;
    for (auto& potion : arr) {
        if (sum + potion >= 0) {
            sum += potion;
            ++ans;
            if (potion < 0) {
                pq.push(potion);
            }
        } else {
            if (!pq.empty() && (sum - pq.top() + potion) >= 0) {
                if (pq.top() < potion) {
                    sum = sum - pq.top() + potion;
                    pq.pop();
                    pq.push(potion);
                }
            }
        }
    }
    cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
