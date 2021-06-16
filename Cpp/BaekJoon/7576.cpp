#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int dr[4]={-1, 1, 0, 0};
const int dc[4]={0, 0, -1, 1};

const int mxN=1e3;
int a[mxN][mxN];
int m, n;

bool can(int r, int c) {
	return r>=0 && c>=0 && m>r && n>c;
}

void solve() {
	cin >> n >> m;
	for(int i=0; i<m; ++i) 
		for(int j=0; j<n; ++j) 
			cin >> a[i][j];
	int ans=0;
	queue<pair<int,int>> q;
	int zero=0;
	for(int i=0; i<m; ++i) {
		for(int j=0; j<n; ++j) {
			if(a[i][j]==1) {
				q.push({i, j});
				a[i][j]=0;
			}
			zero+=a[i][j]==0;
		}
	}
	int d=0;
	while(!q.empty()) {
		int sz=q.size();
		for(int i=0; i<sz; ++i) {
			auto [r, c]=q.front();
			q.pop();
			if(!can(r, c) || a[r][c]!=0) {
				continue;
			}
			a[r][c]=d+1;
			ans=max(d, ans);
			--zero;
			if(zero==0) {
				cout << ans << '\n';
				return;
			}
			for(int i=0; i<4; ++i) {
				q.push({r+dr[i], c+dc[i]});
			}
		}
		++d;
	}
	cout << (zero==0 ? ans : -1) << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
