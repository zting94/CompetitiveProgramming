#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int mxN=1e6;

void solve() {
    vector<int> p(mxN + 1, 0);
    p[2] = 2;
    for(int i = 2; i <= mxN; i += 2) {
        p[i] = 2;
    }
    for(int i = 3; i <= mxN; i += 2) {
        for(int j = i; j <= mxN; j += i) {
            if(p[j] == 0) {
                p[j] = i;
            }
        }
    }
    int m, n;
    cin >> m >> n;
    for(int i = m; i <= n; ++i) {
        if(p[i] == i) {
            cout << i << '\n';
        }
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
