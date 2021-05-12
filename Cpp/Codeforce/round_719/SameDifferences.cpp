#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    long long ans = 0;
    int v;
    for(int i = 0; i < n; ++i) {
        cin >> v;
        v -= i;
        ans += mp[v];
        mp[v]++;
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