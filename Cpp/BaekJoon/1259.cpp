#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

string s;
int n;

bool check(int l, int r) {
	if(l>=r) {
		return true;
	}
	return s[l]==s[r] && check(l+1, r-1);
}

void solve() {
	while(true) {
		cin >> s;
		if(s=="0")
			break;
		n=(int)s.size();
		if(check(0, n-1)) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
