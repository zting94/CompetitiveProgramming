#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int mx=1e5;
const int mxN=100;
const int dx[6]={-1,1,0,0,0,0};
const int dy[6]={0,0,-1,1,0,0};
const int dz[6]={0,0,0,0,1,-1};

int a[mxN][mxN][mxN];
int m, n, h;

class P {
public :
	P(int xx, int yy, int zz) : x(xx), y(yy), z(zz) {}
	int x, y, z;
};

bool can(int x, int y, int z) {
	if(x<0||y<0||z<0||x>=n||y>=m||z>=h)
		return false;
	return true;
}

void solve() {
	cin >> m >> n >> h;
	int zero=0;
	queue<P> q;
	for(int k=0; k<h; ++k) {
		for(int i=0; i<n; ++i) {
			for(int j=0; j<m; ++j) {
				cin >> a[k][i][j];
				zero+=a[k][i][j]==0;
				if(a[k][i][j]==1) {
					q.push(P(i, j, k));
				}
			}
		}
	}
	int d=0;
	int ans=0;
	while(!q.empty()) {
		int sz=q.size();
		for(int i=0; i<sz; ++i) {
			P p=q.front();
			q.pop();
			if(!can(p.x, p.y, p.z) || a[p.z][p.x][p.y]==-1) {
				continue;
			}
			ans=d;
			zero-=a[p.z][p.x][p.y]==0;
			a[p.z][p.x][p.y]=-1;
			for(int i=0; i<6; ++i) {
				q.push(P(p.x+dx[i], p.y+dy[i], p.z+dz[i]));
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
