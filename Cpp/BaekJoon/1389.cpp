#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int mxN=100;

int dist[mxN][mxN];

void solve() {
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			dist[i][j]=(i==j ? 0 : 101);
		}
	}
	for(int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		dist[u][v]=dist[v][u]=1;
	}
	//very important k -> i -> j
	for(int k=0; k<n; ++k) {
		for(int i=0; i<n; ++i) {
			for(int j=0; j<n; ++j) {
				if(dist[i][k]+dist[k][j]<dist[i][j]) {
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	int mx=INT_MAX;
	int ans=0;
	for(int i=n-1; i>=0; --i) {
		int sum=0;
		for(int j=0; j<n; ++j)
			sum+=dist[i][j];
		if(sum<=mx) {
			mx=sum;
			ans=i;
		}
	}
	cout << ans+1 << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
