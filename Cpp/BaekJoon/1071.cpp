#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    multiset<int> s;
    for(int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        s.insert(a);
    }
    int last = -2;
    vector<int> ans(n);
    for(int i = 0; i < n; ++i) {
        if(last + 1 == *s.begin()) {
            auto it = s.upper_bound(last + 1);
            if(it == s.end()) {
                ans[i] = *prev(it);
                s.erase(prev(it));
                for(int j = i; j > 0; --j) {
                    if(ans[j - 1] + 1 != ans[j]) {
                        break;
                    }
                    swap(ans[j - 1], ans[j]);
                }
                last = ans[i];
            } else {
                assert(it != s.end());
                ans[i] = *it;
                last = *it;
                s.erase(it);
            }
        } else {
            ans[i] = *s.begin();
            last = *s.begin();
            s.erase(s.begin());
        }
    }
    for(int i = 0; i < n; ++i) {
        if(i > 0) {
            cout << " ";
        }
        cout << ans[i];
    }
    cout << "\n";
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}