#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    for(auto& i : a) {
        cin >> i;
    }
    sort(a.rbegin(), a.rend());
    for(int i = 0; i < N; ++i) {
        if(i > 0) {
            cout << ' ';
        }
        cout << a[i];
    }
    cout << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCase = 1;
    cin >> testCase;
    for (int t = 0; t < testCase; ++t) {
        solve();
    }

    return 0;
}
