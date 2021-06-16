#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int m, n, x, y;
	cin >> m >> n >> x >> y;
	int g=__gcd(m, n);
	int l=m*n/g;
	while(true) {
		if(x>l) {
			cout << "-1\n";
			return;
		}
		if((x-1)%n+1==y) {
			cout << x << '\n';
			return;
		}
		x+=m;
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int tt;
	cin >> tt;
	while(tt--) {
    	solve();
	}

    return 0;
}
