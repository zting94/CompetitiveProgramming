#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int dr[4]={-1,1,0,0};
const int dc[4]={0,0,-1,1};

const int mxN=100;
int a[mxN][mxN];
int n, m;

bool can(int x, int y) {
	return x>=0 && y>=0 && n>x && m>y;
}

void dfs(int x, int y) {
	if(!can(x, y)||a[x][y]!=0)
		return;
	a[x][y]=-1;
	for(int i=0; i<4; ++i)
		dfs(x+dr[i], y+dc[i]);
}

bool disappear(int x, int y) {
	if(!can(x, y)||a[x][y]!=1) 
		return false;
	int cnt=0;
	for(int i=0; i<4; ++i) {
		if(can(x+dr[i], y+dc[i])&&(a[x+dr[i]][y+dc[i]]==-1))
			++cnt;
	}
	return cnt>=2;
}

void solve() {
	cin >> n >> m;
	queue<pair<int, int>> q;
	queue<pair<int, int>> dfsq;
	for(int i=0; i<n; ++i) 
		for(int j=0; j<m; ++j) 
			cin >> a[i][j];
	for(int i=0; i<n; ++i) {
		if(a[i][0]==0)
			dfs(i, 0);
		if(a[i][m-1]==0)
			dfs(i, m-1);
	}
	for(int i=0; i<m; ++i) {
		if(a[0][i]==0)
			dfs(0, i);
		if(a[n-1][i]==0)
			dfs(n-1, i);
	}
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			if(a[i][j]==1)
				q.push({i,j});

	int ans=0, d=1;
	while(!q.empty()) {
		int sz=q.size();
		for(int i=0; i<sz; ++i) {
			auto [x,y]=q.front();
			q.pop();
			if(!can(x, y)||a[x][y]!=1)
				continue;
			if(!disappear(x, y)) {
				q.push({x,y});
				continue;
			}
			ans=d;
			a[x][y]=0;
			dfsq.push({x, y});
		}
		while(!dfsq.empty()) {
			auto [x,y]=dfsq.front();
			dfsq.pop();
			a[x][y]=0;
			dfs(x, y);
		}
		++d;
	}
	cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
