#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(int i = 0; i < int(n); ++i)
#define RFOR(n) for(int i = n; ~i; --i)

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    a[0] = 9;
    a[1] = 8;
    int init = 9;
    for(int i = 2; i < n; ++i)
        a[i] = (init++ % 10);
    FOR(n)
        cout << a[i];
    cout << '\n';
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