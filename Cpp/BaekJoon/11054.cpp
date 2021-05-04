#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> lis(n);
    vector<int> lds(n);
    vector<int> tmp(1, -1);
    int sz = 0;
    //lis
    for(int i = 0; i < n; ++i) {
        if(tmp.back() < a[i]) {
            tmp.push_back(a[i]);
            sz = tmp.size() - 1;
            lis[i] = sz;
        } else {
            int idx = lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin();
            tmp[idx] = a[i];
            lis[i] = idx;
        }
    }
    tmp = vector<int>(1, -1);
    sz = 0;
    //lds
    for(int i = n - 1; i >= 0; --i) {
        if(tmp.back() < a[i]) {
            tmp.push_back(a[i]);
            sz = tmp.size() - 1;
            lds[i] = sz;
        } else {
            int idx = lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin();
            tmp[idx] = a[i];
            lds[i] = idx;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        //cout << "i : " << i << "\tlis : " << lis[i] << "\tlds : " << lds[i] << endl;
        ans = max(ans, lis[i] + lds[i]);
    }
    cout << ans - 1 << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
    return 0;
}