#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int n, k;
	cin >> n >> k;
	queue<int> q;
	for(int i=1; i<=n; ++i)
		q.push(i);
	int cnt=1;
	cout << "<";
	bool first=true;
	while(!q.empty()) {
		int v=q.front();
		q.pop();
		if(cnt==k) {
			if(!first) {
				cout << ", ";
			}
			cout << v;
			first=false;
			cnt=1;
		} else {
			q.push(v);
			++cnt;
		}
	}
	cout << ">\n";
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
