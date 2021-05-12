#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans = 1e9;
    for(int i = 1; i * i <= n; ++i) {
        ans = min(ans, i - 1 + (int)ceil((double)(n - i) / i));
    }
    cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCase = 1;
    cin >> testCase;
    for(int t = 0; t < testCase; ++t)  {
       solve();
    }

    return 0;
}