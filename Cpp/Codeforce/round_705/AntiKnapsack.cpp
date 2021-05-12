#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(int i = 0; i < int(n); ++i)
#define RFOR(n) for(int i = n; ~i; --i)
#define NL '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    int v = k / 2 + (k & 1);
    cout << n - v << NL;
    for(int i = n; i >= v; --i) {
        if(i == k)
            continue;
        if(i != n)
            cout << ' ';
        cout << i;
    }
    cout << NL;
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