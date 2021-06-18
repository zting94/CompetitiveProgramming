#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int mxN=5e4+1;
int dp[mxN];

int go(int i) {
	if(i<=0)
		return mxN;
	int& ret=dp[i];
	if(ret!=-1)
		return ret;
	ret=mxN;
	for(int j=1; j<sqrt(i); ++j)
		ret=min(ret, go(j*j)+go(i-j*j));
	return ret;
}

void solve() {
	int n;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for(int i=1; i<=sqrt(n); ++i) 
		dp[i*i]=1;
	cout << go(n) << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
