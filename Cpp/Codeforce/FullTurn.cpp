#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(int i = 0; i < int(n); ++i)
#define RFOR(n) for(int i = n; ~i; --i)

int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;
    map<pair<int, int>, int> mp;
    long long ans = 0;
    FOR(n) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        x -= u;
        y -= v;
        int g = gcd(abs(x), abs(y));
        x /= g;
        y /= g;
        mp[{x, y}]++;
        ans += mp[{-x, -y}];
    }
    cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCase = 1;
    cin >> testCase;
    for(int t = 0; t < testCase; ++t) 
       solve();

    return 0;
}