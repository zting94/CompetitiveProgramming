#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int N;
	cin >> N;
	vector<pair<int, int>> a(N);
	for(auto& i : a) 
		cin >> i.first >> i.second;
	sort(a.begin(), a.end(), [](auto& l, auto& r) {
		if(l.second == r.second)
			return l.first < r.first;
		return l.second < r.second;
	});
	int ans = 0;
	int cur = 0;
	for(int i=0; i<N; ++i) {
		if(cur <= a[i].first) {
			++ans;
			cur = a[i].second;
		}
	}
	cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
