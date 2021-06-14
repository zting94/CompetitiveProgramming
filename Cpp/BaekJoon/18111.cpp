#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int mxN=5e2;
int n, m, b;
int arr[mxN][mxN];

int go(int h) {
	int cnt=0;
	int bb=b;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			int cur=arr[i][j];
			while(cur>h) {
				cnt+=2;
				++bb;
				--cur;
			}
			while(cur<h) {
				++cnt;
				--bb;
				++cur;
			}
		}
	}
	return (bb<0 ? INT_MAX : cnt);
}

void solve() {
	cin >> n >> m >> b;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			cin >> arr[i][j];
		}
	}
	int t=INT_MAX, h=0;
	for(int i=256; i>=0; --i) {
		int v=go(i);
		if(v<t) {
			t=v;
			h=i;
		}
	}
	cout << t << ' ' << h << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
