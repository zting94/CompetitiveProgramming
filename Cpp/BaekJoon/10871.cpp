#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int n, x;
	cin >> n >> x;
	int a;
	for(int i=0; i<n; ++i) {
		cin >> a;
		if(a<x) {
			cout << a << ' ';
		}
	}
	cout << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
