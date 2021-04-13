#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(int i = 0; i < int(n); ++i)
#define RFOR(n) for(int i = int(n); ~i; --i)
#define FORI(i, n) for(int i = 0; i < int(n); ++i)
#define NL '\n'

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    if(k == 0) {
        cout << "YES\n";
        return;
    }
    if(n <= k * 2) {
        cout << "NO\n";
        return;
    }
    for(int i = 0; i < k; ++i) {
        if(s[i] != s[n - i - 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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