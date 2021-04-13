#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(int i = 0; i < int(n); ++i)
#define RFOR(n) for(int i = int(n); ~i; --i)
#define NL '\n'

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    if(n % k != 0) {
        cout << -1 << NL;
        return;
    }
    int cnt[26] = {0,};
    for(char c : s)
        cnt[c - 'a']++;
    bool divisible = true;
    FOR(26) {
        if(cnt[i] % k != 0) {
            divisible = false;
            break;
        }
    }
    if(divisible) {
        cout << s << NL;
        return;
    }
    RFOR(n - 1) {
        char c = s[i];
        //if(cnt[c - 'a'] % k == 0)
            //continue;
        int curCharIdx = c - 'a';
        cnt[curCharIdx]--;
        for(int j = curCharIdx + 1; j < 26; ++j) {
            cnt[j]++;
            int need = 0, remain = n - 1 - i;
            for(int v = 0; v < 26; ++v)
                need += (k - cnt[v] % k) % k;
            if(need > remain || (remain - need) % k != 0) {
                cnt[j]--;
                continue;
            }
            for(int v = 0; v < i; ++v)
                cout << s[v];
            cout << (char)('a' + j);
            string tmp;
            for(int v = 0; v < 26; ++v) {
                int tmpNeed = (k - cnt[v] % k) % k;
                tmp += string(tmpNeed, 'a' + v);
            }
            int tmpRemain = remain - tmp.size();
            if(tmpRemain > 0)
                tmp += string(tmpRemain, 'a');
            sort(tmp.begin(), tmp.end());
            cout << tmp << NL;
            return;
        }
    }
    cout << -1 << NL;
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