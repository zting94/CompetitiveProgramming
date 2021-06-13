#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int k,n;
	cin >> k >> n;
	int a[15][15]={0,};
	for(int i=0; i<=n; ++i)
		a[0][i]=i;
	for(int i=1; i<=k; ++i) {
		for(int j=0; j<=n; ++j) {
			for(int l=0; l<=j; ++l) {
				a[i][j]+=a[i-1][l];
			}
		}
	}
	cout << a[k][n] << '\n';
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
