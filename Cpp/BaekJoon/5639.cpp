#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

vector<int> a;
int i;

void dfs(int mn, int mx) {
	if(i>=a.size()|| a[i]<mn || a[i]>mx)
		return;
	int val=a[i++];
	dfs(mn, val);
	dfs(val, mx);
	cout << val << '\n';
}

void solve() {
	int t;
	while(cin >> t) {
		a.push_back(t);
	}
	i=0;
	dfs(INT_MIN, INT_MAX);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
