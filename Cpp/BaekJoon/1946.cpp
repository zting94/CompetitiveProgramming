#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int N;
	cin >> N;
	vector<pair<int, int>> a(N);
	for(int i=0; i<N; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end());
	int mn = INT_MAX;
	int ans=0;
	for(int i=0; i<N; ++i) {
		if(a[i].second>mn) {
			continue;
		}
		++ans;
		mn=min(mn, a[i].second);
	}
	cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int tt;
	cin >> tt;
	while(tt--)  {
	    solve();
	}

    return 0;
}
