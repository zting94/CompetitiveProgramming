#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int N;
    cin >> N;
    vector<int> arr(N);
    int cnt[2] = {0, 0};
    for(auto& i : arr) {
        cin >> i;
        i %= 2;
        cnt[i]++;
    }
    if(cnt[0] == 0 || cnt[1] == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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
