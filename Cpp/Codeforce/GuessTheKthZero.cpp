#include <bits/stdc++.h>

using namespace std;

int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int v;
    cin >> v;
    return v;
}

void solve(int l, int r, int k) {
    if(l >= r) {
        cout << "! " << l << endl;
        return;
    }

    int m = (l + r) / 2;
    int sum = query(l, m);
    int zeros = (m - l + 1) - sum;
    if(zeros >= k) {
        r = m;
    } else  {
        l = m + 1;
        k = k - zeros;
    }
    solve(l, r, k);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t, k;
    cin >> n >> t >> k;
    
    solve(1, n, k);

    return 0;
}