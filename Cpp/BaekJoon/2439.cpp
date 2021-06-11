#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n-i; ++j) {
			cout << ' ';
		}
		for(int j=n-i+1; j<=n; ++j) {
			cout << '*';
		}
		cout << '\n';
	}
	cout << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
