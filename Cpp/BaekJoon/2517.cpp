#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int mxN = 5e5;
int tree[mxN * 4];
int N;
vector<pair<int, int>> arr;

int query(int start, int end, int left, int right, int node = 1) {
    if(right < start || end < left) {
        return 0;
    }
    if(left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return query(start, mid, left, right, node * 2) + query(mid + 1, end, left, right, node * 2 + 1);
}

int update(int start, int end, int idx, int node = 1) {
    if(end < idx || idx < start) {
        return tree[node];
    }
    if(start == end) {
        if(start == idx) {
            tree[node]++;
        }
        return tree[node];
    }
    int mid = (start + end) / 2;
    return tree[node] = update(start, mid, idx, node * 2) + update(mid + 1, end, idx, node * 2 + 1);
}

void solve() {
    cin >> N;
    arr = vector<pair<int, int>>(N);
    for(int i = 0; i < N; ++i) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < N; ++i) {
        arr[i].first = i;
        swap(arr[i].first, arr[i].second);
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < N; ++i) {
        cout << query(0, N - 1, arr[i].second + 1, N - 1) + 1 << '\n';
        update(0, N - 1, arr[i].second);
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
