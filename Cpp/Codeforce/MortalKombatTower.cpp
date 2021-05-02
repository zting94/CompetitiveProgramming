#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> fr(n + 1);
    vector<int> me(n + 1);
    fr[n] = me[n] = 0;
    for(int i = n - 1; i >= 0; --i) {
        fr[i] = me[i + 1] + a[i];
        me[i] = fr[i + 1];
        if(i + 2 <= n) {
            me[i] = min(me[i], fr[i + 2]);
            fr[i] = min(fr[i], me[i + 2] + a[i] + a[i + 1]);
        }
    }
    cout << fr[0] << '\n';
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