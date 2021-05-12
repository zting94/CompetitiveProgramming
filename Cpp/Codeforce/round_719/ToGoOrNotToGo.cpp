#include <bits/stdc++.h>

using namespace std;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int n, m;
long long w;

bool isValid(int r, int c) {
    return 0 <= r && 0 <= c && r < n && c < m;
}

void bfs(int startR, int startC, vector<vector<int>>& distArr, const vector<vector<int>>& arr) {
    queue<pair<int, int>> q;
    int dist = 0;
    q.push({startR, startC});
    while(!q.empty()) {
        int k = q.size();
        for(int i = 0; i < k; ++i) {
            auto [r, c] = q.front();
            q.pop();
            if(!isValid(r, c) || arr[r][c] == -1 || distArr[r][c] != -1) {
                continue;
            }
            distArr[r][c] = dist;
            for(int i = 0; i < 4; ++i) {
                q.push({r + dr[i], c + dc[i]});
            }
        }
        ++dist;
    }
}

void solve() {
    cin >> n >> m >> w;
    vector<vector<int>> arr(n, vector<int>(m));
    vector<vector<int>> fromStart(n, vector<int>(m, -1));
    vector<vector<int>> fromEnd(n, vector<int>(m, -1));
    vector<pair<int, int>> portals;
    for(int r = 0; r < n; ++r) {
        for(int c = 0; c < m; ++c) {
            cin >> arr[r][c];
            if(arr[r][c] >= 1) {
                portals.push_back({r, c});
            }
        }
    }
    bfs(0, 0, fromStart, arr);
    bfs(n - 1, m - 1, fromEnd, arr);
    long long best = 1e18;
    for(auto& [r, c] : portals) {
        if(fromEnd[r][c] != -1) {
            best = min(best, w * fromEnd[r][c] + arr[r][c]);
        }
    }
    long long ans = (fromStart[n - 1][m - 1] == -1) ? 1e18 : (w * fromStart[n - 1][m - 1]);
    for(int r = 0; r < n; ++r) {
        for(int c = 0; c < m; ++c) {
            if(fromStart[r][c] == -1 || arr[r][c] == 0 || best == 1e18) {
                continue;
            }
            ans = min(ans, w * fromStart[r][c] + arr[r][c] + best);
        }
    }
    cout << ((ans == 1e18) ? -1 : ans) << endl;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();

    return 0;
}