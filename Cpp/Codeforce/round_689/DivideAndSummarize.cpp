#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(int i = 0; i < int(n); ++i)
#define RFOR(n) for(int i = int(n); ~i; --i)
#define FORI(i, n) for(int i = 0; i < int(n); ++i)
#define NL '\n'

void build(unordered_set<long long>& s, vector<int>& arr, int left, int right) {
    long long sum = 0;
    for(int i = left; i <= right; ++i)
        sum += arr[i];
    s.insert(sum);
    int midValue = (arr[left] + arr[right]) / 2;
    int idx = -1;
    for(int i = left; i <= right; ++i) {
        if(arr[i] <= midValue)
            idx = i;
        else
            break;
    }
    if(idx == -1 || right <= idx)
        return;
    build(s, arr, left, idx);
    build(s, arr, idx + 1, right);
}

void solve() {
    int n, nQuery;
    cin >> n >> nQuery;
    vector<int> arr(n);
    FOR(n)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    unordered_set<long long> s;
    build(s, arr, 0, n - 1);
    FOR(nQuery) {
        int v;
        cin >> v;
        if(s.find(v) != s.end())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
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