#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int x,y,w,h;
	cin >> x >> y >> w >> h;
	int d1=abs(w-x);
	int d2=x;
	int d3=abs(y-h);
	int d4=y;
	cout << min(min(d1, d2), min(d3, d4)) << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
