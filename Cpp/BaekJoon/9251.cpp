#include <bits/stdc++.h>

using namespace std;

string a, b;
int dp[1001][1001];
int ans;
int n, m;

int lcs(int i, int j) {
    if(i >= n || j >= m) {
        return 0;
    }
    int& ret = dp[i][j];
    if(ret != -1) {
        return ret;
    }
    ret = 0;
    if(a[i] == b[j]) {
        ret = 1 + lcs(i + 1, j + 1);
    }
    ret = max(ret, lcs(i, j + 1));
    ret = max(ret, lcs(i + 1, j));

    return ret;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    ans = 0;
    cin >> a >> b;
    n = a.size();
    m = b.size();

    cout << lcs(0, 0) << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}