#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<int>> edge;
    unordered_map<int, int> cnt;
    vector<bool> placed(n, false);
    for(int i = 0; i < m; ++i) {
        int prev, next;
        cin >> prev >> next;
        --prev;
        --next;
        edge[prev].push_back(next);
        cnt[next]++;
    }
    queue<int> q;
    for(int i = 0; i < n; ++i) {
        if(cnt[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int v = q.front();
        if(cnt[v] > 0) {
            continue;
        }
        q.pop();
        cout << v + 1 << ' ';
        for(int next : edge[v]) {
            cnt[next]--;
            if(cnt[next] == 0) {
                q.push(next);
            }
        }
    }
    
    cout << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}