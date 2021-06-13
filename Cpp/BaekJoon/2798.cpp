#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(auto& i : a)
		cin >> i;
	int sum=0;
	for(int i=0; i<n-2; ++i) {
		for(int j=i+1; j<n-1; ++j) {
			for(int k=j+1; k<n; ++k) {
				int cur=a[i]+a[j]+a[k];
				if(cur>m) {
					continue;
				}
				if(m-sum>m-cur) {
					sum=cur;
				}
			}
		}
	}
	cout << sum << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
