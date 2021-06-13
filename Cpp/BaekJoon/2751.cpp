#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto& i : a)
		cin >> i;
	sort(a.begin(), a.end());
	for(auto& i : a)
		cout << i << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
