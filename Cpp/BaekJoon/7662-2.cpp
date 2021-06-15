#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int k;
	cin >> k;
	string s;
	int v;
	map<int, int> mp;
	for(int i=0; i<k; ++i) {
		cin >> s >> v;
		if(s=="I") {
			mp[v]++;
		} else if(!mp.empty()) {
			if(v==-1) {
				mp.begin()->second--;
				if(mp.begin()->second<=0) {
					mp.erase(mp.begin());
				}
			} else {
				prev(mp.end())->second--;
				if(prev(mp.end())->second<=0) {
					mp.erase(prev(mp.end()));
				}
			}
		}
	}
	if(mp.empty()) {
		cout << "EMPTY\n";
	} else {
		cout << mp.rbegin()->first << " " << mp.begin()->first << '\n';
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int tt;
	cin >> tt;
	while(tt--) {
    	solve();
	}

    return 0;
}
