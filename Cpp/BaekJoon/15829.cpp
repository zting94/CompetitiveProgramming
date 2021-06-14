#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int p=31;
const int M=1234567891;

int myPow(int a, int b) {
	ll ret=1;
	for(int i=0; i<b; ++i) {
		ret*=a;
		ret%=M;
	}
	return ret%M;
}

void solve() {
	int n;
	string s;
	cin >> n >> s;
	ll ans=0;
	for(int i=0; i<n; ++i) {
		ans+=myPow(p, i)*1LL*(s[i]-'a'+1)%M;
		ans%=M;
	}
	cout << ans%M << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
