#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int a;
	int ans=0;
	for(int i=0; i<5; ++i) {
		cin >> a;
		ans+=a*a;
	}
	cout << ans%10 << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
