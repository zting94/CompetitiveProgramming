#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<ll> sum(n+1, 0);
	for(int i=0; i<n; ++i) {
		int t;
		cin >> t;
		sum[i+1]=sum[i]+t;
	}
	for(int i=0; i<m; ++i) {
		int l, r;
		cin >> l >> r;
		cout << sum[r]-sum[l-1] << '\n';
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
