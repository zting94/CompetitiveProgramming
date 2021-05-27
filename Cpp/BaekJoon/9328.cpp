#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int R, C;
bool vis[101][101];
bool canVisit[101][101];
vector<string> arr;
unordered_set<char> key;
bool progress;

const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};

bool isValid(int r, int c) {
    if(r < 0 || c < 0 || r >= R || c >= C) {
        return false;
    }
    return true;
}

int dfs1(int r, int c) {
    if(!isValid(r, c) || arr[r][c] == '*' || vis[r][c]) {
        return 0;
    }
    canVisit[r][c] = true;
    if('A' <= arr[r][c] && arr[r][c] <= 'Z') {
        if(key.find(arr[r][c]) == key.end()) {
            return 0;
        }
    }
    progress = true;
    vis[r][c] = true;
    int ret = 0;
    if('a' <= arr[r][c] && arr[r][c] <= 'z') {
        key.insert('A' + arr[r][c] - 'a');
    } else if(arr[r][c] == '$') {
        ++ret;
    }
    arr[r][c] = '.';
    for(int i = 0; i < 4; ++i) {
        ret += dfs1(r + dr[i], c + dc[i]);
    }
    return ret;
}

int dfs2(int r, int c) {
    if(!isValid(r, c) || arr[r][c] == '*' || vis[r][c] || !canVisit[r][c]) {
        return 0;
    }
    canVisit[r][c] = true;
    if('A' <= arr[r][c] && arr[r][c] <= 'Z') {
        if(key.find(arr[r][c]) == key.end()) {
            return 0;
        }
    }
    progress = true;
    vis[r][c] = true;
    int ret = 0;
    if('a' <= arr[r][c] && arr[r][c] <= 'z') {
        key.insert('A' + arr[r][c] - 'a');
    } else if(arr[r][c] == '$') {
        ++ret;
    }
    arr[r][c] = '.';
    for(int i = 0; i < 4; ++i) {
        ret += dfs1(r + dr[i], c + dc[i]);
    }
    return ret;
}


void solve() {
    cin >> R >> C;
    arr = vector<string>(R);
    key.clear();
    for(auto& s : arr) {
        cin >> s;
    }
    string k;
    cin >> k;
    if(k != "0") {
        for(char c : k)  {
            key.insert('A' + c - 'a');
        }
    }
    queue<pair<int, int>> keys;
    memset(vis, 0, sizeof(vis));
    memset(canVisit, 0, sizeof(canVisit));
    for(int r = 0; r < R; ++r) {
        for(int c = 0; c < C; ++c) {
            if('A' <= arr[r][c] && arr[r][c] <= 'Z') {
                keys.push({r, c});
            }
        }
    }
    int ans = 0;
    for(int r = 0; r < R; ++r) {
        if(arr[r][0] != '*') {
            ans += dfs1(r, 0);
        }
        if(arr[r][C - 1] != '*') {
            ans += dfs1(r, C - 1);
        }
    }
    for(int c = 0; c < C; ++c) {
        if(arr[0][c] != '*') {
            ans += dfs1(0, c);
        }
        if(arr[R - 1][c] != '*') {
            ans += dfs1(R - 1, c);
        }
    }
    while(true) {
        int sz = keys.size();
        progress = false;
        for(int i = 0; i < sz; ++i) {
            auto [r, c] = keys.front();
            keys.pop();
            ans += dfs2(r, c);
            keys.push({r, c});
        }
        if(!progress) {
            break;
        }
    }
    cout << ans << '\n';
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
