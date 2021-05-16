#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& i : a)
        cin >> i;
    vector<int> lcs;
    lcs.push_back(-1);
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(lcs.back() < a[i]) {
            lcs.push_back(a[i]);
            ans = lcs.size() - 1;
        } else {
            auto idx = lower_bound(lcs.begin(), lcs.end(), a[i]) - lcs.begin();
            lcs[idx] = a[i];
        }
    }
    cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}