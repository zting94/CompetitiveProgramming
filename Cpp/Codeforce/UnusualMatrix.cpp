#include <bits/stdc++.h>

using namespace std;

#define FORI(i, n) for(int i = 0; i < int(n); ++i)
#define FOR(n) for(int i = 0; i < int(n); ++i)
#define RFOR(n) for(int i = int(n); ~i; --i)
#define NL '\n'

bool isMatch(vector<vector<int>>& mat, const vector<vector<int>>& ref) {
    int n = mat.size();
    FORI(r, n) {
        if(mat[r][0] == ref[r][0])
            continue;
        FORI(c, n) {
            mat[r][c] ^= 1;
        }
    }
    FORI(c, n) {
        int v = mat[0][c] ^ ref[0][c];
        for(int r = 1; r < n; ++r) {
            if((mat[r][c] ^ ref[r][c]) != v)
                return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    vector<vector<int>> ref(n, vector<int>(n));
    FORI(i, n) {
        string s;
        cin >> s;
        FORI(j, n) {
            mat[i][j] = s[j] - '0';
        }
    }
    FORI(i, n) {
        string s;
        cin >> s;
        FORI(j, n) {
            ref[i][j] = s[j] - '0';
        }
    }
    FORI(times, 2) {
        if(isMatch(mat, ref)) {
            cout << "YES\n";
            return;
        }
        FOR(n) {
            mat[i][0] ^= 1;
        }
    }
    cout << "NO\n";
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCase = 1;
    cin >> testCase;
    for(int t = 0; t < testCase; ++t) 
       solve();

    return 0;
}