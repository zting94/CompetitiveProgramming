#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(int i = 0; i < int(n); ++i)
#define RFOR(n) for(int i = int(n); ~i; --i)
#define FORI(i, n) for(int i = 0; i < int(n); ++i)
#define NL '\n'

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    vector<pair<int, int>> corner;
    for(int r = 0; r < n; ++r) {
        for(int c = 0; c < n; ++c) {
            if(s[r][c] == '*') {
                corner.push_back({r, c});
            }
        }
    }
    int r1, r2, c1, c2;
    auto& p1 = corner[0];
    auto& p2 = corner[1];

    r1 = min(p1.first, p2.first);
    c1 = min(p1.second, p2.second);
    r2 = max(p1.first, p2.first);
    c2 = max(p1.second, p2.second);

    if(r1 == r2) {
        if(r1 == 0) {
            ++r2;
        } else {
            --r1;
        }
    }
    if(c1 == c2) {
        if(c1 == 0) {
            ++c2;
        } else {
            --c1;
        }
    }
    s[r1][c1] = '*';
    s[r1][c2] = '*';
    s[r2][c2] = '*';
    s[r2][c1] = '*';
    for(int r = 0; r < n; ++r) {
        for(int c = 0; c < n; ++c) {
            cout << s[r][c];
        }
        cout << '\n';
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCase = 1;
    cin >> testCase;
    for(int t = 0; t < testCase; ++t)  {
       solve();
    }

    return 0;
}