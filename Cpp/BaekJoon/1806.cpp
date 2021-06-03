#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int N;
    ll S;
    cin >> N >> S;
    vector<ll> a(N);
    ll all = 0;
    for(auto& i : a) {
        cin >> i;
        all += i;
    }
    if(S > all) {
        cout << 0 << '\n';
        return;
    }
    ll sum = 0;
    int l = 0;
    int ans = INT_MAX;
    for(int i = 0; i < N; ++i) {
        sum += a[i];
        while(sum - a[l] >= S) {
            ans = min(ans, i - l);
            sum -= a[l++];
        }
    }
    cout << (ans == INT_MAX ? N : ans) << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
