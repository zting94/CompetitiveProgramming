#include <bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> mp;
	int mxC=0;
	for(auto& i : a) {
		cin >> i;
		mp[i]++;
		mxC=max(mxC, mp[i]);
	}
	vector<int> v;
	for(auto it=mp.begin(); it!=mp.end(); ++it) {
		if(it->second==mxC)
			v.push_back(it->first);
	}
	sort(a.begin(), a.end());
	sort(v.begin(), v.end());
	cout << round((double)accumulate(a.begin(), a.end(), 0LL)/n) << '\n';
	cout << a[n/2] << '\n';
	cout << (v.size()==1 ? v[0] : v[1]) << '\n';
	cout << a[n-1]-a[0] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}


