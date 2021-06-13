#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int a,b;
	cin >> a >> b;
	int g=__gcd(a,b);
	cout << g << '\n';
	cout << a/g*b << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
