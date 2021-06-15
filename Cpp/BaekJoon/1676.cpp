#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int n;
	cin >> n;
	int two=0, five=0;
	for(int i=1; i<=n; ++i) {
		int t=i;
		while(t%2==0) {
			++two;
			t/=2;
		}
		while(t%5==0) {
			++five;
			t/=5;
		}
	}
	cout << min(two, five) << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
