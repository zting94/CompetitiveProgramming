#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int n, m;
vector<int> a;

void dfs(vector<int>& v) {
	if(v.size()==m) {
		for(auto& i : v)
			cout << i << ' ';
		cout << '\n';
		return;
	}
	for(int i=0; i<n; ++i) {
		if(v.empty()||v.back()<=a[i]) {
			v.push_back(a[i]);
			dfs(v);
			v.pop_back();
		}
	}
}

void solve() {
	cin >> n >> m;
	a=vector<int>(n);
	for(auto& i : a)
		cin >> i;
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	n=a.size();
	vector<int> v;
	dfs(v);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
