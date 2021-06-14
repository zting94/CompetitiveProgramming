#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int bino(int n, int k) {
	if(n==k||k==0) {
		return 1;
	}
	return bino(n-1,k) + bino(n-1, k-1);
}

void solve() {
	int n,k;
	cin >> n >> k;
	cout << bino(n, k) << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
