#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int dr[4]={-1,1,0,0};
const int dc[4]={0,0,-1,1};

const int mxN=1e2;
string a[mxN];
int n, m;
int v[mxN][mxN];

bool can(int r, int c) {
	if(r<0||c<0||r>=n||c>=m) {
		return false;
	}
	return true;
}

void solve() {
	cin >> n >> m;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	memset(v, -1, sizeof(v));
	int d=1;
	queue<pair<int, int>> q;
	q.push({0, 0});
	while(!q.empty()) {
		int sz=q.size();
		for(int i=0; i<sz; ++i) {
			auto [r, c]=q.front();
			q.pop();
			if(!can(r, c)||v[r][c]!=-1||a[r][c]=='0') {
				continue;
			}
			if(r==n-1&&c==m-1) {
				cout << d << '\n';
				return;
			}
			v[r][c]=d;
			for(int j=0; j<4; ++j) {
				q.push({r+dr[j], c+dc[j]});
			}
		}
		++d;
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
