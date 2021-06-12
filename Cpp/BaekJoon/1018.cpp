#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int x=8;
int ans;
string s[51];

void check(int r, int c) {
	int ww=0, bb=0;
	for(int i=r; i<r+x; ++i) {
		for(int j=c; j<c+x; ++j) {
			if((i+j)%2) {
				if(s[i][j]=='W')
					++ww;
				else
					++bb;
			} else {
				if(s[i][j]=='W')
					++bb;
				else
					++ww;
			}
		}
	}
	ans=min(ans, min(ww, bb));
}

void solve() {
	int n, m;
	cin >> n >> m;
	ans=INT_MAX;
	for(int i=0; i<n; ++i)
		cin >> s[i];
	for(int i=0; i<n-x+1; ++i) {
		for(int j=0; j<m-x+1; ++j) {
			check(i, j);
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
