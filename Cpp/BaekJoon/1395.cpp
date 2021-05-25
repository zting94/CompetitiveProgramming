#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int mxN = 1e5;
int N, M;
int arr[mxN];
int tree[mxN * 4];
bool rev[mxN * 4];

void prop(int start, int end, int node) {
    if (!rev[node]) {
        return;
    }
    tree[node] = (end - start + 1) - tree[node];
    if (start != end) {
        rev[node * 2] = !rev[node * 2];
        rev[node * 2 + 1] = !rev[node * 2 + 1];
    }
    rev[node] = false;
}

void update(int start, int end, int left, int right, int node) {
    prop(start, end, node);
    if (end < left || right < start) {
        return;
    }
    if (left <= start && end <= right) {
        tree[node] = (end - start + 1) - tree[node];
        if (start != end) {
            rev[node * 2] = !rev[node * 2];
            rev[node * 2 + 1] = !rev[node * 2 + 1];
        }
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, left, right, node * 2);
    update(mid + 1, end, left, right, node * 2 + 1);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int start, int end, int left, int right, int node) {
    prop(start, end, node);
    if (end < left || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return query(start, mid, left, right, node * 2) +
           query(mid + 1, end, left, right, node * 2 + 1);
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, l, r;
        cin >> a >> l >> r;
        --l, --r;
        if (a == 0) {
            update(0, N - 1, l, r, 1);
        } else {
            cout << query(0, N - 1, l, r, 1) << '\n';
        }
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
