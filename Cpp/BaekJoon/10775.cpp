#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, p;
    cin >> n >> p;
    set<int> s;
    for(int i = 1; i <= n; ++i) {
        s.insert(i);
    }
    int ans = 0;
    bool can = true;
    for(int i = 0; i < p; ++i) {
        int v;
        cin >> v;
        if(!can) {
            continue;
        }
        auto it = s.lower_bound(v);
        if(it == s.begin()) {
            if(*it != v) {
                can = false;
            } else {
                ++ans;
                s.erase(it);
            }
        } else {
            ++ans;
            if(*it == v) {
                s.erase(it);
            } else {
                s.erase(prev(it));
            }
        }
    }
    cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}