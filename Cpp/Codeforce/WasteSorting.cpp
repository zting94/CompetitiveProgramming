#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(int i = 0; i < int(n); ++i)
#define RFOR(n) for(int i = n; ~i; --i)

void solve() {
    vector<int> c(3);
    vector<int> a(5);
    FOR(3)
        cin >> c[i];
    FOR(5)
        cin >> a[i];
    FOR(3) {
        c[i] -= a[i];
        if(c[i] < 0) {
            cout << "NO\n";
            return;
        }
    }
    a[3] = max(0, a[3] - c[0]);
    a[4] = max(0, a[4] - c[1]);
    if(c[2] >= a[3] + a[4])
        cout << "YES\n";
    else   
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