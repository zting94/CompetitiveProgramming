#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(int i = 0; i < int(n); ++i)
#define RFOR(n) for(int i = n; ~i; --i)

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    FOR(n)
        cin >> a[i];
    unordered_set<int> s;
    for(int i = 0; i < n - 1; ++i) {
        for(int j = i + 1; j < n; ++j) {
            int v = a[j] - a[i];
            if(s.find(v) == s.end())
                s.insert(v);
        }
    }
    cout << s.size() << '\n';
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