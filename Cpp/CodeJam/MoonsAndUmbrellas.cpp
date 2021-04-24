#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(int i = 0; i < int(n); ++i)
#define RFOR(n) for(int i = int(n); ~i; --i)
#define FORI(i, n) for(int i = 0; i < int(n); ++i)
#define NL '\n'

void solve() {
	int CJ, JC;
	string s;
	cin >> CJ >> JC >> s;
	int n = s.size();
	vector<int> jdp(n, 1e9);
	vector<int> cdp(n, 1e9);
	jdp[0] = cdp[0] = 0;
	for(int i = 1; i < n; ++i) {
		int prevMin = min(jdp[i - 1], cdp[i - 1]);
		if(s[i] == '?') {
			if(s[i - 1] == 'J') {
				jdp[i] = prevMin;
				cdp[i] = cdp[i - 1] + JC;
			} else if(s[i - 1] == 'C') {
				jdp[i] = jdp[i - 1] + CJ;
				cdp[i] = prevMin;
			} else {
				jdp[i] = min(cdp[i - 1] + CJ, jdp[i - 1]);
				cdp[i] = min(jdp[i - 1] + JC, cdp[i - 1]);
			}

		} else if(s[i] == 'J') {
			if(s[i - 1] == 'C') {
				jdp[i] = jdp[i - 1] + CJ;
				cdp[i] = cdp[i - 1] + CJ;
			} else if(s[i - 1] == '?') {
				cdp[i] = cdp[i - 1] + CJ;
				jdp[i] = jdp[i - 1];
			} else {
				cdp[i] = cdp[i - 1];
				jdp[i] = jdp[i - 1];
			}
		} else if(s[i] == 'C') {
			if(s[i - 1] == 'J') {
				jdp[i] = jdp[i - 1] + JC;
				cdp[i] = cdp[i - 1] + JC;
			} else if(s[i - 1] == '?') {
				cdp[i] = cdp[i - 1];
				jdp[i] = jdp[i - 1] + JC;
			} else {
				cdp[i] = cdp[i - 1];
				jdp[i] = jdp[i - 1];
			}
		}
	}
	cout << min(jdp[n - 1], cdp[n - 1]) << NL;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCase = 1;
    cin >> testCase;
    for(int t = 1; t <= testCase; ++t) {
    	cout << "Case #" << t << ": ";
    	solve();
    }

    return 0;
}