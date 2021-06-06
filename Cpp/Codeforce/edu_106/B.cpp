#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    string s;
    cin >> s;
    int i = s.find("11");
    int j = s.rfind("00");
    if (i != -1 && j != -1 && i < j) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCase = 1;
    cin >> testCase;
    for (int t = 0; t < testCase; ++t) {
        solve();
    }

    return 0;
}
