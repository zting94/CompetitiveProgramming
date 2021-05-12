#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(int i = 0; i < int(n); ++i)
#define RFOR(n) for(int i = int(n); ~i; --i)
#define FORI(i, n) for(int i = 0; i < int(n); ++i)
#define NL '\n'

void solve() {
    string s;
    vector<int> num(2);
    cin >> num[0] >> num[1] >> s;
    int n = (int)s.size();
    if(n & 1) {
        if(s[n / 2] != '?') {
            num[s[n / 2] - '0']--;
        }
    }
    for(int i = 0; i < n / 2; ++i) {
        if(s[i] == '?' && s[n - i - 1] == '?') {
            continue;
        }
        if(s[i] == '?') {
            s[i] = s[n - i - 1];
            num[s[i] - '0'] -= 2;
        } else if(s[n - i - 1] == '?') {
            s[n - i - 1] = s[i];
            num[s[n - i - 1] - '0'] -= 2;
        } else if(s[i] != s[n - i - 1]) {
            cout << "-1\n";
            return;
        } else {
            num[s[i] - '0'] -= 2;
        }
    }
    for(int i = 0; i < n / 2; ++i) {
        assert(s[i] == s[n - i - 1]);
        if(s[i] != '?') {
            continue;
        }
        if(num[0] >= 2) {
            s[i] = s[n - i - 1] = '0';
            num[0] -= 2;
        } else if(num[1] >= 2) {
            s[i] = s[n - i - 1] = '1';
            num[1] -= 2;
        } else {
            cout << "-1\n";
            return;
        }
    }
    if((n & 1) && s[n / 2] == '?') {
        if(num[0] > 0) {
            s[n / 2] = '0';
            num[0]--;
        } else if(num[1] > 0) {
            s[n / 2] = '1';
            num[1]--;
        }
    }
    if(num[0] == 0 && num[1] == 0) {
        cout << s << '\n';
    } else {
        cout << "-1\n";
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