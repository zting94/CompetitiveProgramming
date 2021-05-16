#include <bits/stdc++.h>

using namespace std;

int N, K;
int cache[101][100001];
int W[101], V[101];

int dp(int i, int remain) {
    if(i + 1 == N) {
        return 0;
    }
    int& ret = cache[i + 1][remain];
    if(ret != -1) {
        return ret;
    }
    ret = max(ret, dp(i + 1, remain));
    if (W[i + 1] <= remain) {
        ret = max(ret, V[i + 1] + dp(i + 1, remain - W[i + 1]));
    }
    return ret;
}

void solve() {
    cin >> N >> K;
    memset(cache, -1, sizeof(cache));
    for(int i = 0; i < N; ++i) {
        cin >> W[i] >> V[i];
    }
    cout << dp(-1, K) << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}