#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	string s;
	cin >> s;
	int ans=0;
	int cnt=0;
	for(char c : s) {
		if(c=='O') {
			++cnt;
			ans+=cnt;
		} else {
			cnt=0;
		}
	}
	cout << ans << '\n';
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
