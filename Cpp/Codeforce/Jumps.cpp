#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(int i = 0; i < int(n); ++i)
#define RFOR(n) for(int i = n; ~i; --i)
#define NL '\n'

void solve() {
    int x;
    cin >> x;
    int n = 1;
    while(n * (n + 1) / 2 < x)
        ++n;
    if(n * (n + 1) / 2 == x + 1)
        ++n;
    cout << n << NL;
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