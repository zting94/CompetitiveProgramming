#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	vector<int> a(9);
	for(auto& i : a)
		cin >> i;
	auto i=max_element(a.begin(), a.end());
	cout << *i << endl;
	cout << i-a.begin()+1 << endl;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
