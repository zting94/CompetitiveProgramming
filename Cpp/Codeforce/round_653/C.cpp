#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    int ans = 0;
    for(char c : s) {
        if(c == '(') {
            ++cnt;
        } else {
            --cnt;
            if(cnt < 0) {
                ++ans;
                cnt = 0;
            }
        }
    }
    cout << ans << '\n';
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
