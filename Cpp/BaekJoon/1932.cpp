#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int mxN=501;
vector<int> a[mxN];
int n;

void solve() {
	cin >> n;
	for(int i=0; i<n; ++i) {
		a[i].assign(i+1, 0);
		for(int j=0; j<=i; ++j) {
			cin >> a[i][j];
		}
	}
	a[n].assign(n+1, 0);
	for(int i=n-1; i>=0; --i) {
		for(int j=0; j<a[i].size(); ++j) {
			a[i][j]=max(a[i+1][j], a[i+1][j+1])+a[i][j];
		}
	}

	cout << a[0][0] << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
