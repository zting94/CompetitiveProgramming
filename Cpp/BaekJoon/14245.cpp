#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int mxN = 5e5;
int N, M;
int arr[mxN];
int tree[mxN * 4];
int lazy[mxN * 4];

void init(int start, int end, int node) {
    if(start == end) {
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    init(start, mid, node * 2);
    init(mid + 1, end, node * 2 + 1);
}

void prop(int start, int end, int node) {
    if(lazy[node] == 0) {
        return;
    }
    tree[node] ^= lazy[node];
    if(start != end) {
        lazy[node * 2] ^= lazy[node];
        lazy[node * 2 + 1] ^= lazy[node];
    }
    lazy[node] = 0;
}

void update(int start, int end, int left, int right, int node, int val) {
    prop(start, end, node);
    if(right < start || end < left) {
        return;
    }
    if(left <= start && end <= right) {
        tree[node] ^= val;
        if(start != end) {
            lazy[node * 2] ^= val;
            lazy[node * 2 + 1] ^= val;
        }
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, left, right, node * 2, val);
    update(mid + 1, end, left, right, node * 2 + 1, val);
}

int query(int start, int end, int idx, int node) {
    prop(start, end, node);
    if(idx < start || end < idx) {
        return 0;
    }
    if(start == idx && end == idx) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return query(start, mid, idx, node * 2) ^ query(mid + 1, end, idx, node * 2 + 1);
}

void solve() {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    init(0, N - 1, 1);
    cin >> M;
    while(M--) {
        int t;
        cin >> t;
        if(t == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            update(0, N - 1, l, r, 1, val);
        } else {
            int a;
            cin >> a;
            cout << query(0, N - 1, a, 1) << '\n';
        }
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
