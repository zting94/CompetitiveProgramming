#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int sheep = count_if(s.begin(), s.end(), [](auto& c) {
        return c == '*';
    });
    int idx = -1;
    int cnt = -1;
    for(int i = 0; i < n; ++i) {
        if(s[i] != '*') {
            continue;
        }
        ++cnt;
        if(cnt == sheep / 2) {
            idx = i - sheep / 2;
            break;
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; ++i) {
        if(s[i] != '*') {
            continue;
        }
        ans += abs(idx - i);
        ++idx;
    }
    cout << ans << '\n';
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