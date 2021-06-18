#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for(int i=0; i<n; ++i) {
		cin >> a[i].first;
		a[i].second=i;
	}
	sort(a.begin(), a.end());
	int rank=0;
	int prev=a[0].first;
	for(int i=0; i<n; ++i) {
		if(prev<a[i].first)
			++rank;
		prev=a[i].first;
		a[i].first=rank;
	}
	sort(a.begin(), a.end(), [](auto& l, auto& r) {
		return l.second < r.second;
	});
	for(int i=0; i<n; ++i) {
		if(i>0) {
			cout << ' ';
		}
		cout << a[i].first;
	}
	cout << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
