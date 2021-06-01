#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int N;
ll M;
vector<ll> mem;
vector<int> cost;

ll cache[101][10001];
int sum;

ll dp(int idx, int cur) {
    if(idx + 1 == N || cur < 0) {
        return 0;
    }
    ll& ret = cache[idx + 1][cur];
    if(ret != -1) {
        return ret;
    }
    ret = dp(idx + 1, cur);
    if(cost[idx + 1] <= cur) {
        ret = max(ret, dp(idx + 1, cur - cost[idx + 1]) + mem[idx + 1]);
    }
    return ret;
}

void solve() {
    cin >> N >> M;
    memset(cache, -1, sizeof(cache));
    mem = vector<ll>(N);
    cost = vector<int>(N);
    sum = 0;
    for(auto& i : mem) {
        cin >> i;
    }
    for(auto& i : cost) {
        cin >> i;
        sum += i;
    }
    for(int i = 0; i <= sum; ++i) {
        if(dp(-1, i) >= M) {
            cout << i << '\n';
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
