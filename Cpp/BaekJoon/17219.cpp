#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int n, m;
	cin >> n >> m;
	string a, b;
	unordered_map<string, string> mp;
	for(int i=0; i<n; ++i) {
		cin >> a >> b;
		mp[a]=b;
	}
	for(int i=0; i<m; ++i) {
		cin >> a;
		cout << mp[a] << '\n';
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
