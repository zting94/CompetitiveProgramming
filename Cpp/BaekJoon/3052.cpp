#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	set<int> s;
	for(int i=0; i<10; ++i) {
		int a;
		cin >> a;
		s.insert(a%42);
	}
	cout << s.size() << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
