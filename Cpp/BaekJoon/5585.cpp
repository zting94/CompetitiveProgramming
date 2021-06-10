#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int a[6] = {500, 100, 50, 10, 5, 1};

void solve() {
	int N;
	cin >> N;
	N = 1000 - N;
	int ans = 0;
	for(int i=0; i<6; ++i) {
		if(a[i]>N)
			continue;
		while(a[i]<=N) {
			N -= a[i];
			++ans;
		}
	}
	cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
