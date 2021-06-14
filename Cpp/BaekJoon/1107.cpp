#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int cur=100;
	int n, m;
	unordered_set<int> s;
	cin >> n >> m;
	for(int i=0; i<m; ++i) {
		int t;
		cin >> t;
		s.insert(t);
	}
	int ans=abs(n-cur);
	for(int i=0; i<=1e6+30; ++i) {
		bool can=true;
		int cnt=(i==0 ? 1 : 0);
		int t=i;
		if(s.find(t)!=s.end()) {
			continue;
		}
		while(t) {
			int v=t%10;
			if(s.find(v)!=s.end()) {
				can=false;
				break;
			}
			t/=10;
			++cnt;
		}
		if(!can) {
			continue;
		}
		cnt+=abs(n-i);
		ans=min(ans, cnt);
	}
	cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
