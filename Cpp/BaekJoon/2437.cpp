#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    int sum = 0;
    for(auto& i : a) {
        if(i > sum + 1) {
            break;
        }
        sum += i;
    }
    cout << sum + 1 << '\n';
}

// 1 1 2 3 6 7 30
// 1 2 4 7 13 20 50

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}