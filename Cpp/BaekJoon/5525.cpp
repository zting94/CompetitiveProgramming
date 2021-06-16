#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int n, sz;
	string s;
	cin >> n >> sz >> s;
	int ans=0;
	for(int i=0; i<sz; ++i) {
		if(s[i]=='O') {
			continue;
		}
		int k=0;
		while(i+2<sz && s[i+1]=='O' && s[i+2]=='I') {
			++k;
			if(k==n) {
				++ans;
				--k;
			}
			i+=2;
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
