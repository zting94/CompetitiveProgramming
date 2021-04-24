#include <bits/stdc++.h>

using namespace std;

int ans;

void check(const vector<int>& masks, int mask) {
    int cur = 0;
    for(int m : masks) {
        if((m & mask) == m) {
            ++cur;
        }
    }
    ans = max(cur, ans);
}

void dfs(const vector<int>& masks, int idx, int curMask, int k) {
    if(k == 0) {
        check(masks, curMask);
        return;
    }

    for(int i = idx + 1; i < 26; ++i) {
        if(curMask & (1 << (i + 1))) {
            continue;
        }
        curMask |= (1 << (i + 1));
        dfs(masks, i, curMask, k - 1);
        curMask ^= (1 << (i + 1));
    }
}

void solve() {
    ans = 0;
    int n, k;
    cin >> n >> k;
    vector<string> str(n);
    vector<int> masks(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> str[i];
        for(char c : str[i]) {
            masks[i] |= (1 << (c - 'a' + 1));
        }
    }
    dfs(masks, -1, 0, k);

    cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}