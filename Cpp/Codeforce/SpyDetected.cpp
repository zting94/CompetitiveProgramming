#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(int i = 0; i < int(n); ++i)
#define RFOR(n) for(int i = int(n); ~i; --i)
#define FORI(i, n) for(int i = 0; i < int(n); ++i)
#define NL '\n'

void solve() {
    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    bool flag = false;
    if(a != b && b == c) {
        cout << "1\n";
        flag = true;
    } else if(a != c && a == b) {
        cout << "3\n";
        flag = true;
    } else if(a != b && a == c) {
        cout << "2\n";
        flag = true;
    }
    int t;
    for(int i = 4; i <= n; ++i) {
        cin >> t;
        if(t != a && !flag) {
            cout << i << '\n';
        }
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