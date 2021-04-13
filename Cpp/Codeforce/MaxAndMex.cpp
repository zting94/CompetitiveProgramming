#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(int i = 0; i < int(n); ++i)
#define RFOR(n) for(int i = int(n); ~i; --i)
#define FORI(i, n) for(int i = 0; i < int(n); ++i)
#define NL '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    unordered_set<int> s;
    int maxVal = INT_MIN;
    FOR(n) {
        int v;
        cin >> v;
        maxVal = max(v, maxVal);
        s.insert(v);
    }
    if(k == 0) {
        cout << n << NL;
        return;
    }
    int minVal = 0;
    while(s.find(minVal) != s.end())
        ++minVal;
    if(minVal == maxVal + 1) {
        cout << n + k << NL;
        return;
    }
    int addVal = ceil(((double)minVal + maxVal) / 2);
    if(s.find(addVal) != s.end())
        cout << n << NL;
    else
        cout << n + 1 << NL;
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