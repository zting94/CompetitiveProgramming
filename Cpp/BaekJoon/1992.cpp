#include <bits/stdc++.h>

using namespace std;

int n;

bool check(const vector<string>& str, int sr, int er, int sc, int ec) {
    char ch = str[sr][sc];
    for(int r = sr; r < er; ++r) {
        for(int c = sc; c < ec; ++c) {
            if(str[r][c] != ch) {
                return false;
            }
        }
    }
    return true;
}

string quad(const vector<string>& str, int sr, int er, int sc, int ec) {
    if(check(str, sr, er, sc, ec)) {
        return string(1, str[sr][sc]);
    }
    if(sr + 1 == er || sc + 1 == ec) {
        return string(1, str[sr][sc]);
    }
    int mr = (sr + er) / 2;
    int mc = (sc + ec) / 2;

    return "(" 
        + quad(str, sr, mr, sc, mc)
        + quad(str, sr, mr, mc, ec)
        + quad(str, mr, er, sc, mc)
        + quad(str, mr, er, mc, ec)
        + ")";
}

void solve() {
    cin >> n;
    vector<string> str(n);
    for(int i = 0; i < n; ++i) {
        cin >> str[i];
    }
    cout << quad(str, 0, n, 0, n);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}