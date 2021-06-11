#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto& i : a) 
		cin >> i;
	sort(a.begin(), a.end());
	set<int> idxs;
	for(int i=0; i<n; ++i)
		idxs.insert(i);
	int ans=0;
	for(int i=0; i<n-1; i+=2) {
		if(a[i]>0 || a[i+1]>0)
			break;
		ans+=max(a[i]*a[i+1], a[i]+a[i+1]);
		idxs.erase(i);
		idxs.erase(i+1);
	}
	for(int i=n-1; i>0; i-=2) {
		if(a[i]<=0 || a[i-1]<=0)
			break;
		ans+=max(a[i]*a[i-1], a[i]+a[i-1]);
		idxs.erase(i);
		idxs.erase(i-1);
	}
	for(int i : idxs)
		ans+=a[i];
	cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
