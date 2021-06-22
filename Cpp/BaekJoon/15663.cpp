#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int n, m;
vector<int> a;
vector<vector<int>> ans;

void dfs(vector<int>& v, int mask=0, int cnt=0) {
	if(cnt==m) {
		ans.push_back(v);
		return;
	}
	for(int i=0; i<n; ++i) {
		if(mask&(1<<i))
			continue;
		v.push_back(a[i]);
		dfs(v, mask|(1<<i), cnt+1);
		v.pop_back();
	}
}

void solve() {
	cin >> n >> m;
	a=vector<int>(n);
	for(auto& i : a)
		cin >> i;
	sort(a.begin(), a.end());
	vector<int> v;
	dfs(v);
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for(auto& t : ans) {
		for(int i : t)
			cout << i << ' ';
		cout << '\n';
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
