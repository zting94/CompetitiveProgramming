#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> dp(n, -1);
    vector<int> lis(1, INT_MIN);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for(int i = 0; i < n; ++i) {
        if(lis.back() < arr[i]) {
            lis.push_back(arr[i]);
            dp[i] = lis.size() - 1;
        } else {
            int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
            lis[idx] = arr[i];
            dp[i] = idx;
        }
    }
    int cnt = lis.size() - 1;
    vector<int> ans;
    for(int i = n - 1; ~i && cnt; --i) {
        if(dp[i] == cnt) {
            ans.push_back(arr[i]);
            --cnt;
        }
    }
    cout << ans.size() << '\n';
    for(int i = ans.size() - 1; ~i; --i)  {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();

    return 0;
}