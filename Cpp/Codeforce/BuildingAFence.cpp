#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(int i = 0; i < int(n); ++i)
#define RFOR(n) for(int i = n; ~i; --i)

bool solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    FOR(n)
        cin >> arr[i];
    int mn = arr[0], mx = arr[0];
    for(int i = 1; i < n; ++i) {
        mn = max(mn - k + 1, arr[i]);
        mx = min(mx + k - 1, arr[i] + k - 1);
        if(mn > mx)
            return false;
    }
    if(arr[n - 1] < mn || arr[n - 1] > mx)
        return false;
    return true;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCase = 1;
    cin >> testCase;
    for(int t = 0; t < testCase; ++t)  {
        if(solve()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}