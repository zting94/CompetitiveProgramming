#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int mxN=1e5+1;
int a[mxN][3];
int n;

void solve() {
	cin >> n;
	for(int i=0; i<n; ++i) 
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	vector<vector<int>> mx(2, vector<int>(3, 0));
	vector<vector<int>> mn(2, vector<int>(3, 1e9));
	for(int i=0; i<3; ++i)
		mn[0][i]=0;
	for(int i=1; i<=n; ++i) {
		for(int j=0; j<3; ++j) {
			int& mnn=mn[i%2][j];
			int& mxx=mx[i%2][j];
			mnn=mn[(i-1)%2][j]+a[i-1][j];
			mxx=mx[(i-1)%2][j]+a[i-1][j];
			if(j>=1) {
				mnn=min(mnn, mn[(i-1)%2][j-1]+a[i-1][j]);
				mxx=max(mxx, mx[(i-1)%2][j-1]+a[i-1][j]);
			}
			if(j<=1) {
				mnn=min(mnn, mn[(i-1)%2][j+1]+a[i-1][j]);
				mxx=max(mxx, mx[(i-1)%2][j+1]+a[i-1][j]);
			}
		}
	}
	cout << max(max(mx[n%2][0], mx[n%2][1]), mx[n%2][2]) << ' '
		 << min(min(mn[n%2][0], mn[n%2][1]), mn[n%2][2]) << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
