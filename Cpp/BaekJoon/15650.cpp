#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int n, m;

void go(int i, vector<int>& v) {
	if(v.size()==m) {
		for(auto& w : v)
			cout << w << ' ';
		cout << '\n';
		return;
	}
	for(int next=i+1; next<=n; ++next) {
		v.push_back(next);
		go(next, v);
		v.pop_back();
	}
}

void solve() {
	cin >> n >> m;
	vector<int> v;
	go(0, v);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
