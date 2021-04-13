#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(int i = 0; i < int(n); ++i)
#define RFOR(n) for(int i = int(n); ~i; --i)
#define FORI(i, n) for(int i = 0; i < int(n); ++i)
#define NL '\n'

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> miner;
    vector<pair<int, int>> diamond;
    FOR(n * 2) {
        int x, y;
        cin >> x >> y;
        if(x == 0) {
            miner.push_back({x, abs(y)});
        } else {
            diamond.push_back({abs(x), y});
        }
    }
    sort(miner.begin(), miner.end());
    sort(diamond.begin(), diamond.end());
    double ans = 0;
    FOR(n) {
        ans += sqrt((double)miner[i].second * miner[i].second + (double)diamond[i].first * diamond[i].first);
    }
    cout.precision(18);
    cout << ans << NL;
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