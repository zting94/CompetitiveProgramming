#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int N;
	cin >> N;
	vector<int> a(N);
	for(auto& i : a)
		cin >> i;
	sort(a.rbegin(), a.rend());
	int ans = 0;
	for(int i=0; i<N; ++i) {
		ans = max(ans, a[i] * (i + 1));
	}
	cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
