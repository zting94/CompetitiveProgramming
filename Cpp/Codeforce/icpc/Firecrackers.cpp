#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(int i = 0; i < int(n); ++i)
#define RFOR(n) for(int i = n; ~i; --i)

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<int> fire(m);
    FOR(m) 
        cin >> fire[i];
    sort(fire.begin(), fire.end());
    int remainTime = (a > b) ? (n - b) : (b - 1);
    int canDropCount = abs(b - a) - 1;
    int ans = 0;
    int idx = min(m - 1, (int)(lower_bound(fire.begin(), fire.end(), remainTime) - fire.begin()));
    for(int i = idx; ~i && 0 < canDropCount; --i) {
        if(fire[i] < remainTime) {
            ++ans;
            --remainTime;
            --canDropCount;
        }
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