#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(int i = 0; i < int(n); ++i)
#define RFOR(n) for(int i = int(n); ~i; --i)
#define FORI(i, n) for(int i = 0; i < int(n); ++i)
#define NL '\n'

void solve() {
    int n, N;
    cin >> n;
    N = n + 2;
    vector<long long> arr(N);
    multiset<long long> s;
    long long sum = 0;
    FOR(N) {
        cin >> arr[i];
        s.insert(arr[i]);
        sum += arr[i];
    }
    sort(arr.begin(), arr.end());
    long long v = sum - arr[N - 1] - arr[N - 1];
    if(s.find(v) != s.end()) {
        if(v == arr[N - 1] && s.count(v) < 2) {
        } else {
            long long newSum = sum - v - arr[N - 1];
            if(newSum == arr[N - 1]) {
                s.erase(s.find(arr[N - 1]));
                s.erase(s.find(v));
                for (long long i : s) {
                    cout << i << " ";
                }
                cout << '\n';
                return;
            }
        }
    }
    sum -= arr[N - 1];
    if((sum - arr[N - 2]) == arr[N - 2]) {
        for(int i = 0; i < N - 2; ++i) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    cout << "-1\n";
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