#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int n;
	cin >> n;
	deque<int> dq;
	for(int i=0; i<n; ++i) {
		string s;
		cin >> s;
		if(s=="push_back") {
			int v;
			cin >> v;
			dq.push_back(v);
		} else if(s=="push_front") {
			int v;
			cin >> v;
			dq.push_front(v);
		} else if(s=="pop_front") {
			if(dq.empty()) {
				cout << "-1\n";
			} else {
				int v=dq.front();
				dq.pop_front();
				cout << v << '\n';
			}
		} else if(s=="pop_back") {
			if(dq.empty()) {
				cout << "-1\n";
			} else {
				int v=dq.back();
				dq.pop_back();
				cout << v << '\n';
			}
		} else if(s=="size") {
			cout << dq.size() << '\n';
		} else if(s=="empty") {
			cout << dq.empty() << '\n';
		} else if(s=="front") {
			cout << (dq.empty() ? -1 : dq.front()) << '\n';
		} else if(s=="back") {
			cout << (dq.empty() ? -1 : dq.back()) << '\n';
		} else {
			assert(false);
		}
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
