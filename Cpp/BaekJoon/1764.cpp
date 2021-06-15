#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int n, m;
	cin >> n >> m;
	unordered_set<string> s;
	for(int i=0; i<n; ++i) {
		string a;
		cin >> a;
		s.insert(a);
	}
	vector<string> ans;
	for(int i=0; i<m; ++i) {
		string a;
		cin >> a;
		if(s.find(a)!=s.end()) {
			ans.push_back(a);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for(auto& a : ans)
		cout << a << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
