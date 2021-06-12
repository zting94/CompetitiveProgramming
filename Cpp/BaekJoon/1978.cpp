#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if(a == 1) {
            continue;
        }
        int cnt = 0;
        for(int j = 2; j * j <= a; ++j) {
            if(a % j == 0) {
                ++cnt;
                break;
            }
        }
        ans+=(cnt == 0);
    }
    cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
