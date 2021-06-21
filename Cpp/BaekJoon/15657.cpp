#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int n, m;
vector<int> a;

void dfs(vector<int>& v) {
    if(v.size() == m) {
        for(auto& w : v) {
            cout << w << ' ';
        }
        cout << '\n';
        return;
    }
    for(int idx = 0; idx < n; ++idx) {
        if(v.empty() || v.back() <= a[idx]) {
            v.push_back(a[idx]);
            dfs(v);
            v.pop_back();
        }
    }
}

void solve() {
    cin >> n >> m;
    a = vector<int>(n);
    for(auto& i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    vector<int> v;
    dfs(v);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
