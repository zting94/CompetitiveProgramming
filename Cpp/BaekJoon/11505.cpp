#include <bits/stdc++.h>

using namespace std;

int MOD = 1e9 + 7;
vector<long long> arr;
vector<long long> tree;

long long init(int l, int r, int idx) {
    if(l == r) {
        return tree[idx] = arr[l] % MOD;
    }
    int mid = (l + r) / 2;
    return tree[idx] = (init(l, mid, idx * 2) * init(mid + 1, r, idx * 2 + 1)) % MOD;
}

void update(int l, int r, int nodeIdx, int arrIdx, long long val) {
    if(r < arrIdx || arrIdx < l) {
        return;
    }
    if(l == r) {
        tree[nodeIdx] = val % MOD;
        return;
    }
    int mid = (l + r) / 2;
    update(l, mid, nodeIdx * 2, arrIdx, val);
    update(mid + 1, r, nodeIdx * 2 + 1, arrIdx, val);
    tree[nodeIdx] = (tree[nodeIdx * 2] * tree[nodeIdx * 2 + 1]) % MOD;
}

long long query(int s, int e, int l, int r, int nodeIdx) {
    if(e < l || r < s) {
        return 1;
    }
    if(l <= s && e <= r) {
        return tree[nodeIdx] % MOD;
    }
    int mid = (s + e) / 2;
    long long lp = query(s, mid, l, r, nodeIdx * 2);
    long long rp = query(mid + 1, e, l, r, nodeIdx * 2 + 1);

    return (lp * rp) % MOD;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    arr = vector<long long>(n, 0);
    tree = vector<long long>(n * 4, 0);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    init(0, n - 1, 1);
    for(int i = 0; i < m + k; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) {
            update(0, n - 1, 1, b - 1, c);
        } else {
            cout << query(0, n - 1, b - 1, c - 1, 1) << "\n";
        }
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}