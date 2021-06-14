#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, string>> a(n);
	for(auto& i : a)
		cin >> i.first >> i.second;
	stable_sort(a.begin(), a.end(), [](auto& l, auto& r) {
			return l.first < r.first;
	});
	for(auto& i : a) {
		cout << i.first << " " << i.second << '\n';
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
