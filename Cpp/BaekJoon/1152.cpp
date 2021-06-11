#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	string s;
	getline(std::cin, s);
	int n=s.size();
	int l=0, r=n-1;
	while(isspace(s[l])) {
		++l;
	}
	while(isspace(s[r])) {
		--r;
	}
	if(l>r) {
		cout << 0 << '\n';
		return;
	}
	int ans=std::count_if(s.begin()+l, s.begin()+r+1, [](auto c) {
		return isspace(c);
	});
	cout << ans+1 <<'\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
