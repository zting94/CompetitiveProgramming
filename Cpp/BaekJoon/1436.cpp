#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int n;
	cin >> n;
	for(int i=666; i<= INT_MAX; ++i) {
		string s=to_string(i);
		if(s.find("666")!=string::npos) {
			--n;
		}
		if(n==0) {
			cout << i << '\n';
			break;
		}
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
