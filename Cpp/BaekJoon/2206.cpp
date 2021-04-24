#include <bits/stdc++.h>

using namespace std;

int n, m;
const int dr[4] = {-1, 0, 0, 1};
const int dc[4] = {0, -1, 1, 0};

bool isValid(int r, int c) {
    if(r < 0 || c < 0 || n <= r || m <= c) {
        return false;
    }
    return true;
}

void solve() {
    cin >> n >> m;
    vector<string> arr(n);
    vector<vector<int>> dist(n, vector<int>(m, std::numeric_limits<int>::max()));
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(2, 0)));
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    queue<tuple<int, int, int, int>> q;
    q.push({0, 0, 1, 0});
    while(!q.empty()) {
        auto [r, c, curDist, changed] = q.front();
        q.pop();
        if(!isValid(r, c) || visited[r][c][changed]) {
            continue;
        }
        dist[r][c] = min(dist[r][c], curDist);
        visited[r][c][changed] = true;
        for(int i = 0; i < 4; ++i) {
            if(isValid(r + dr[i], c + dc[i])) {
                if(arr[r + dr[i]][c + dc[i]] == '1' && changed == 0) {
                    q.push({r + dr[i], c + dc[i], curDist + 1, 1});
                } else if(arr[r + dr[i]][c + dc[i]] == '0') {
                    q.push({r + dr[i], c + dc[i], curDist + 1, changed});
                }
            }
        }
    }

    if(dist[n - 1][m - 1] == std::numeric_limits<int>::max()) {
        cout << "-1\n";
    } else {
        cout << dist[n - 1][m - 1] << '\n';
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}