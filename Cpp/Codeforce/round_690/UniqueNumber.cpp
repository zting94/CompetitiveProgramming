#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(int i = 0; i < int(n); ++i)
#define RFOR(n) for(int i = n; ~i; --i)
#define NL '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> ans;
    int last = 9, sum = 0;
    while(sum < n && last > 0) {
        ans.push_back(min(n - sum, last));
        sum += last;
        --last;
    }
    if(sum < n)
        cout << -1 << NL;
    else {
        RFOR(ans.size() - 1)
            cout << ans[i];
        cout << NL;
    }
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