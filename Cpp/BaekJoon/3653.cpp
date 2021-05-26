#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int mxN = 1e5;
const int mxM = 1e5;
int tree[(mxN + mxM) * 4];
int N, M;

int init(int start, int end, int node = 1) {
    if(start == end) {
        if(start < N) {
            tree[node] = 1;
        }
        return tree[node];
    }
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1 ,end, node * 2 + 1);
}

int update(int start, int end, int idx, int val, int node = 1) {
    if(idx < start || end < idx) {
        return tree[node];
    }
    if(start == end) {
        if(start == idx) {
            tree[node] = val;
        }
        return tree[node];
    }
    int mid = (start + end) / 2;
    return tree[node] = update(start, mid, idx, val, node * 2) + update(mid + 1, end, idx, val, node * 2 + 1);
}

int query(int start, int end, int left, int right, int node = 1) {
    if(end < left || right < start) {
        return 0;
    }
    if(left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return query(start, mid, left, right, node * 2) + query(mid + 1, end, left, right, node * 2 + 1);
}

void solve() {
    cin >> N >> M;
    unordered_map<int, int> index;
    for(int i = 1; i <= N; ++i) {
        index[i] = N - i;
    }
    int last = N + M - 1;
    init(0, last);
    int cur = N;
    //cout << "init : " << query(0, last, 0, last, 1) << endl;
    for(int i = 0; i < M; ++i) {
        int num;
        cin >> num;
        cout << N - query(0, last, 0, index[num]) << " ";
        update(0, last, index[num], 0);
        index[num] = cur;
        update(0, last, cur, 1);
        ++cur;
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }

    return 0;
}
