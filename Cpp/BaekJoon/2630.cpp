#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int mxN=2187;
int a[mxN][mxN];
int n;
unordered_map<int, int> mp;

bool chk(int sr, int sc, int sz) {
	bool z=true, o=true;
	for(int r=sr; r<sr+sz; ++r) {
		for(int c=sc; c<sc+sz; ++c) {
			z&=a[r][c]==0;
			o&=a[r][c]==1;
		}
	}
	if(!z&&!o) {
		return false;
	}
	mp[o==true]++;
	return true;
}

void dfs(int sr, int sc, int sz) {
	if(chk(sr, sc, sz)) {
		return;
	}
	int v=sz/2;
	for(int i=0; i<2; ++i) {
		for(int j=0; j<2; ++j) {
			dfs(sr+i*v, sc+j*v, v);
		}
	}
}

void solve() {
	cin >> n;
	for(int i=0; i<n; ++i) 
		for(int j=0; j<n; ++j)
			cin >> a[i][j];
	dfs(0, 0, n);

	cout << mp[0] << '\n' << mp[1] << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
