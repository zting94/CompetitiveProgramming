#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int N;
int ans;
bool rows[31];
bool cols[31];
bool lefts[31];
bool rights[31];

bool canPlace(int r, int c) {
    if(rows[r]) {
        return false;
    }
    if(cols[c]) {
        return false;
    }
    if(lefts[N - r + c]) {
        return false;
    }
    if(rights[r + c]) {
        return false;
    }
    return true;
}

void dfs(int r) {
    if(r == N) {
        ++ans;
        return;
    }
    for(int c = 0; c < N; ++c) {
        if(!canPlace(r, c)) {
            continue;
        }
        rows[r] = cols[c] = lefts[N - r + c] = rights[r + c] = true;
        dfs(r + 1);
        rows[r] = cols[c] = lefts[N - r + c] = rights[r + c] = false;
    }
}

void solve() {
    cin >> N;
    ans = 0;
    dfs(0);
    cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
