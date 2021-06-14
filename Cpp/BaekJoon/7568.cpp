#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for(auto& i : a) {
		cin >> i.first >> i.second;
	}
	for(int i=0; i<n; ++i) {
		int cnt=1;
		for(int j=0; j<n; ++j) {
			if(i==j) {
				continue;
			}
			if(a[j].first>a[i].first&&a[j].second>a[i].second) {
				++cnt;
			}
		}
		if(i > 0) {
			cout << ' ';
		}
		cout << cnt;
	}
	cout << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
