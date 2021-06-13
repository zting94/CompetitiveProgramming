#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	vector<int> a(3);
	while(true) {
		cin >> a[0] >> a[1] >> a[2];
		if(!a[0]&&!a[1]&&!a[2])
			break;
		sort(a.begin(), a.end());
		if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2]) {
			cout << "right\n";
		} else {
			cout << "wrong\n";
		}
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
