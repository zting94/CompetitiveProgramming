#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;


/*
ai - bi > -(aj - bj)
*/

void solve() {
    int N;
    cin >> N;
    vector<int> a(N), b(N), c(N);
    for(auto& i : a) {
        cin >> i;
    }
    for(auto& i : b) {
        cin >> i;
    }
    for(int i = 0; i < N; ++i) {
        c[i] = a[i] - b[i];
    }
    sort(c.begin(), c.end());
    ll ans = 0;
    for(int i = 0; i < N; ++i) {
        if(c[i] <= 0) {
            continue;
        }
        int idx = upper_bound(c.begin(), c.end(), -c[i]) - c.begin();
        ans += i - idx;
    }
    cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
