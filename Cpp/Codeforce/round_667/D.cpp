#include <bits/stdc++.h>

using namespace std;

int digitSum(long long num) {
    int v = 0;
    while (num > 0) {
        v += (num % 10);
        num /= 10;
    }
    return v;
}

void solve() {
    long long n, s;
    cin >> n >> s;
    if (digitSum(n) <= s) {
        cout << "0\n";
        return;
    }
    long long p = 1;
    long long ans = 0;
    for (int i = 0; i < 18; ++i) {
        int digit = ((n / p) % 10);
        long long need = p * (10 - digit);
        n += need;
        ans += need;
        if (digitSum(n) <= s) {
            break;
        }
        p *= 10;
    }
    cout << ans << '\n';
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