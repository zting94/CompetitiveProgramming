#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int mx=1e6;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n, vector<int>(n, mx));
	for(int i=0; i<n; ++i) 
		for(int j=0; j<n; ++j)  {
			int a;
			cin >> a;
			if(a==1)
				g[i][j]=1;
		}
	for(int k=0; k<n; ++k) 
		for(int i=0; i<n; ++i) 
			for(int j=0; j<n; ++j) 
				if(g[i][k]+g[k][j]<g[i][j]) 
					g[i][j]=1;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			if(j>0)
				cout << ' ';
			cout << (g[i][j]==mx ? 0 : 1);
		}
		cout << '\n';
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
