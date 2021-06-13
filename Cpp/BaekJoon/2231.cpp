#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int n;
	cin >> n;
	for(int i=1; i<=1000000; ++i) {
		int t=i;
		int cnt=i;
		while(t) {
			cnt+=t%10;
			t/=10;
		}
		if(cnt==n) {
			cout << i << '\n';
			return;
		}
	}
	cout << 0 << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
