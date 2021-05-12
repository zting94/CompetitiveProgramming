#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(int i = 0; i < int(n); ++i)
#define RFOR(n) for(int i = int(n); ~i; --i)
#define FORI(i, n) for(int i = 0; i < int(n); ++i)
#define NL '\n'

void solve() {
    int n, memory;
    cin >> n >> memory;
    vector<int> tmp(n);
    FOR(n)
        cin >> tmp[i];
    vector<int> a, b;
    FOR(n) {
        int v;
        cin >> v;
        if(v == 1)
            a.push_back(tmp[i]);
        else
            b.push_back(tmp[i]);
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    int numB = 0, sumB = 0; //first find b, where sumB >= memory
    for(int i = 0; i < b.size(); ++i) {
        if(sumB >= memory)
            break;
        sumB += b[i];
        numB++;
    }
    int ans = INT_MAX;
    if(sumB >= memory)
        ans = numB * 2;
    int sumA = 0;
    FOR(a.size()) {
        sumA += a[i];
        while(numB > 0 && sumA + sumB - b[numB - 1] >= memory) {
            --numB;
            sumB -= b[numB];
        }
        if(sumA + sumB >= memory)
            ans = min(ans, i + 1 + 2 * numB);
    }
    cout << ((ans == INT_MAX) ? -1 : ans) << NL;
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