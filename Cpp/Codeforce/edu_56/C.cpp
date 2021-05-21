#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n / 2);
    for (auto& i : b) {
        cin >> i;
    }
    a[0] = 0;
    a[n - 1] = b[0];
    for (int i = 1; i < n / 2; ++i) {
        if (b[i] <= a[n - i]) {
            a[n - i - 1] = b[i];
            a[i] = 0;
        } else {
            a[n - i - 1] = a[n - i];
            a[i] = b[i] - a[n - i - 1];
        }
        if (a[i] < a[i - 1]) {
            long long diff = a[i - 1] - a[i];
            a[i] += diff;
            a[n - i - 1] -= diff;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            cout << ' ';
        }
        cout << a[i];
    }
    cout << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
