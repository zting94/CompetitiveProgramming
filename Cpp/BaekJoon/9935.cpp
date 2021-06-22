#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	string s, v;
	cin >> s >> v;
	stack<pair<int, int>> stk;
	for(int i=0; i<s.size(); ++i) {
		if(stk.empty()) {
			stk.push({i, s[i]==v[0]?0:-1});
		} else if(stk.top().second==-1) {
			if(s[i]==v[0]) {
				stk.push({i, 0});
			} else {
				stk.push({i, -1});
			}
		} else {
			if(s[i]==v[stk.top().second+1]) {
				stk.push({i, stk.top().second+1});
			} else if(s[i]==v[0]) {
				stk.push({i, 0});
			} else {
				stk.push({i, -1});
			}
		}
		if(stk.top().second+1==v.size()) {
			for(int k=v.size()-1; k>=0; --k) {
				assert(!stk.empty());
				assert(v[k]==v[stk.top().second]);
				stk.pop();
			}
		}
	}
	if(stk.empty()) {
		cout << "FRULA\n";
		return;
	}
	string ans;
	while(!stk.empty()) {
		ans+=s[stk.top().first];
		//cout << s[stk.top().first] << ' ' << stk.top().second << endl;
		stk.pop();
	}
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
