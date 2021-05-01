#include <bits/stdc++.h>

using namespace std;

long long mydiv(long long a, long long b) {
    return (a + b - 1) / b;
}

long long solve() {
    long long x, y, k;
    cin >> x >> y >> k;
    long long ans = k;
    long long need = y * k + k - 1;
    ans += mydiv(need, x - 1);
    return ans;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCase = 1;
    cin >> testCase;
    for(int t = 0; t < testCase; ++t)  {
       cout << solve() << '\n';
    }

    return 0;
}