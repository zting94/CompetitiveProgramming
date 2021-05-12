#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(int i = 0; i < int(n); ++i)
#define RFOR(n) for(int i = n; ~i; --i)

void solve() {
    int n;
    cin >> n;
    set<int> s;
    FOR(n) {
        int v;
        cin >> v;
        if(s.find(v) != s.end())
            ++v;
        if(s.find(v) != s.end())
            continue;
        s.insert(v);
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