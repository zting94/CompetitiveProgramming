#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int mxN=1e5+1;
int a[mxN][2];
int dp[mxN][2];

void solve() {
	int n;
	cin >> n;
	for(int i=0; i<n; ++i) 
		cin >> a[i][0];
	for(int i=0; i<n; ++i)
		cin >> a[i][1];
	dp[0][0]=dp[0][1]=0;
	dp[1][0]=a[0][0];
	dp[1][1]=a[0][1];
	// 두 칸 전까지만 보는 이유는
	// 세 칸 전에서 오는 경우는, 중간에 한 칸을 더 거칠 수 있기 때문에
	// 값이 항상 더 커지는 경우가 존재하기 때문임!
	for(int i=2; i<=n; ++i) {
		dp[i][0]=max(dp[i-1][1], dp[i-2][1])+a[i-1][0];
		dp[i][1]=max(dp[i-1][0], dp[i-2][0])+a[i-1][1];
	}
	cout << max(dp[n][0], dp[n][1]) << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int tt;
	cin >> tt;
	while(tt--)
    	solve();

    return 0;
}
