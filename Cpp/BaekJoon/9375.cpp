#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int n;
	cin >> n;
	unordered_map<string, int> mp;
	for(int i=0; i<n; ++i) {
		string a, b;
		cin >> a >> b;
		mp[b]++;
	}
	int ans=1;
	for(auto& [s, v] : mp) {
		ans*=(v+1);
	}
	cout << ans-1 << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int tt;
	cin >> tt;
	while(tt--) {
    	solve();
	}

    return 0;
}
