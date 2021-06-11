#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int w, h;
	cin >> w >> h;
	int t=w*60+h;
	t-=45;
	if(t<0)
		t+=24*60;
	cout << t/60 << " " << t%60 << '\n'; 
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
