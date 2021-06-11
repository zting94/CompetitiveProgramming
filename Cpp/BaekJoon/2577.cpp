#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int a,b,c;
	cin >> a >> b >> c;
	int m=a*b*c;
	int cnt[10]={0,};
	while(m>0) {
		cnt[m%10]++;
		m/=10;
	}
	for(int i=0; i<10; ++i) {
		cout << cnt[i] << '\n';
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
