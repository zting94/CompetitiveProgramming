#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5;
long long arr[mxN];
long long tree[mxN * 4];
int N, M;

long long init(int start, int end, int node) {
    if(start == end) {
        return tree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    long long left = init(start, mid, node * 2);
    long long right = init(mid + 1, end, node * 2 + 1);

    return tree[node] = min(left, right);
}

long long query(int start, int end, int queryStart, int queryEnd, int node) {
    if(end < queryStart || queryEnd < start) {
        return std::numeric_limits<long long>::max();
    }
    if(queryStart <= start && end <= queryEnd) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    long long left = query(start, mid, queryStart, queryEnd, node * 2);
    long long right = query(mid + 1, end, queryStart, queryEnd, node * 2 + 1);

    return min(left, right);
}

void solve() {
    cin >> N >> M;  
    for(int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    init(0, N - 1, 1);
    for(int i = 0; i < M; ++i) {
        int s, e;
        cin >> s >> e;
        --s;
        --e;
        cout << query(0, N - 1, s, e, 1) << '\n';
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}