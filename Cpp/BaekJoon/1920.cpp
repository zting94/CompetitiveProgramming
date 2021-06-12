#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n, m;
    cin >> n;
    unordered_set<int> s;
    for(int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        s.insert(a);
    }
    cin >> m;
    for(int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        cout << (s.find(a) != s.end()) << '\n';
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
