#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N=21;

void solve() {
	int m;
	cin >> m;
	int v=0, a;
	string s;
	for(int i=0; i<m; ++i) {
		cin >> s;
		if(s=="add") {
			cin >> a;
			v|=(1<<a);
		} else if(s=="remove") {
			cin >> a;
			v&=(~(1<<a));
		} else if(s=="check") {
			cin >> a;
			cout << ((v&(1<<a))!=0) << '\n';
		} else if(s=="toggle") {
			cin >> a;
			v^=(1<<a);
		} else if(s=="all") {
			v=(1<<N)-1;
		} else if(s=="empty") {
			v=0;
		} else {
			assert(false);
		}
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
