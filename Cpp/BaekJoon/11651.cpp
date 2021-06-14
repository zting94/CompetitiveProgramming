#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for(auto& i : a)
		cin >> i.first >> i.second;
	sort(a.begin(), a.end(), [](auto& l, auto& r) {
		return l.second==r.second? l.first<r.first: l.second<r.second;
	});
	for(auto& i : a) {
		cout << i.first << ' ' << i.second << '\n';
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
