#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	string s;
	cin >> s;
	vector<int> a(26, -1);
	for(int i=0; i<s.size(); ++i) {
		if(a[s[i]-'a']!=-1) {
			continue;
		}
		a[s[i]-'a']=i;
	}
	for(int i=0; i<26; ++i) {
		if(i>0) {
			cout << ' ';
		}
		cout << a[i];
	}
	cout << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
