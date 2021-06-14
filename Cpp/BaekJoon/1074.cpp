#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int vis;
int n, r, c;
bool done;

void dfs(int up, int down, int left, int right) {
	if(done) {
		return;
	}
	if(up==down && left==right) {
		++vis;
		if(up==r && left==c) {
			cout << vis-1 << '\n';
			done=true;
		}
		return;
	}
	int row_mid=(up+down)/2;
	int col_mid=(left+right)/2;
	int cnt=(row_mid-up+1)*(col_mid-left+1);

	if(r<=row_mid && c<=col_mid) {
		dfs(up, row_mid, left, col_mid);
	} else if(r<=row_mid && c>col_mid) {
		vis+=cnt;
		dfs(up, row_mid, col_mid+1, right);
	} else if(r>row_mid && c<=col_mid) {
		vis+=2*cnt;
		dfs(row_mid+1, down, left, col_mid);
	} else if(r>row_mid && c>col_mid) {
		vis+=3*cnt;
		dfs(row_mid+1, down, col_mid+1, right);
	} else {
		assert(false);
	}
}

void solve() {
	cin >> n >> r >> c;
	vis=0;
	done=false;
	dfs(0, pow(2, n)-1, 0, pow(2,n)-1);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
