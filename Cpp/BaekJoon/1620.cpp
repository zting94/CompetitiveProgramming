#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int n, m;
	cin >> n >> m;
	unordered_map<int, string> mpi;
	unordered_map<string, int> mps;
	for(int i=1; i<=n; ++i) {
		string s;
		cin >> s;
		mpi[i]=s;
		mps[s]=i;
	}
	for(int i=0; i<m; ++i) {
		string s;
		cin >> s;
		if('0'<=s[0]&&s[0]<='9') {
			cout << mpi[stoi(s)] << '\n';
		} else {
			cout << mps[s] << '\n';
		}
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
