#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int n, m;
const int mxN=500;
int a[mxN][mxN];
const int aa[8][4][2]={
	{{0, 0},{0, 1},{0, 2},{0, 3}},
	{{0, 0},{1, 0},{2, 0},{3, 0}},
	{{0, 0},{0, -1},{0, -2},{0, -3}},
	{{0, 0},{-1, 0},{-2, 0},{-3, 0}},

	{{0, 0},{0, 1},{0, 2},{0, 3}},
	{{0, 0},{1, 0},{2, 0},{3, 0}},
	{{0, 0},{0, -1},{0, -2},{0, -3}},
	{{0, 0},{-1, 0},{-2, 0},{-3, 0}}
};
const int bb[8][4][2]={
	{{0, 0},{0, 1},{1, 0},{1, 1}},
	{{0, 0},{1, 0},{0, -1},{1, -1}},
	{{0, 0},{0, -1},{-1, 0},{-1, -1}},
	{{0, 0},{0, 1},{-1, 0},{-1, 1}},

	{{0, 0},{0, 1},{1, 0},{1, 1}},
	{{0, 0},{1, 0},{0, -1},{1, -1}},
	{{0, 0},{0, -1},{-1, 0},{-1, -1}},
	{{0, 0},{0, 1},{-1, 0},{-1, 1}}
};
const int cc[8][4][2]={
	{{0, 0},{1, 0},{2, 0},{2, 1}},
	{{0, 0},{0, -1},{0, -2},{1, -2}},
	{{0, 0},{-1, 0},{-2, 0},{-2, -1}},
	{{0, 0},{0, 1},{0, 2},{-1, 2}},

	{{0, 0},{1, 0},{2, 0},{2, -1}},
	{{0, 0},{0, -1},{0, -2},{-1, -2}},
	{{0, 0},{-1, 0},{-2, 0},{-2, 1}},
	{{0, 0},{0, 1},{0, 2},{1, 2}}
};
const int dd[8][4][2]={
	{{0, 0},{1, 0},{1, 1},{2, 1}},
	{{0, 0},{0, -1},{1, -1},{1, -2}},
	{{0, 0},{-1, 0},{-1, -1},{-2, -1}},
	{{0, 0},{0, 1},{-1, 1},{-1, 2}},

	{{0, 0},{1, 0},{1, -1},{2, -1}},
	{{0, 0},{0, -1},{-1, -1},{-1, -2}},
	{{0, 0},{-1, 0},{-1, 1},{-2, 1}},
	{{0, 0},{0, 1},{1, 1},{1, 2}}
};
const int ee[8][4][2]={
	{{0, 0},{0, 1},{0, 2},{1, 1}},
	{{0, 0},{1, 0},{2, 0},{1, -1}},
	{{0, 0},{0, -1},{0, -2},{-1, -1}},
	{{0, 0},{-1, 0},{-2, 0},{-1, 1}},

	{{0, 0},{0, 1},{0, 2},{1, 1}},
	{{0, 0},{1, 0},{2, 0},{1, -1}},
	{{0, 0},{0, -1},{0, -2},{-1, -1}},
	{{0, 0},{-1, 0},{-2, 0},{-1, 1}}
};

bool can(int x, int y) {
	return x>=0 && y>=0 && n>x && m>y;
}

int sum(const int arr[4][4][2], int x, int y) {
	int ret=0;
	for(int k=0; k<8; ++k) {
		int sum=0;
		for(int j=0; j<4; ++j) {
			if(!can(x+arr[k][j][0], y+arr[k][j][1])) {
				sum=0;
				break;
			}
			sum+=a[x+arr[k][j][0]][y+arr[k][j][1]];
		}
		ret=max(ret, sum);
	}
	return ret;
}

void solve() {
	cin >> n >> m;
	int ans=0;
	for(int i=0; i<n; ++i) 
		for(int j=0; j<m; ++j)
			cin >> a[i][j];
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			ans=max(ans, sum(aa, i, j));
			ans=max(ans, sum(bb, i, j));
			ans=max(ans, sum(cc, i, j));
			ans=max(ans, sum(dd, i, j));
			ans=max(ans, sum(ee, i, j));
		}
	}
	cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
