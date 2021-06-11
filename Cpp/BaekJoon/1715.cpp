#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=0; i<N; ++i) {
		int t;
		cin >> t;
		pq.push(t);
	}
	int ans=0;
	while(pq.size()>1) {
		int a=pq.top();
		pq.pop();
		int b=pq.top();
		pq.pop();
		ans += a+b;
		pq.push(a+b);
	}
	cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
