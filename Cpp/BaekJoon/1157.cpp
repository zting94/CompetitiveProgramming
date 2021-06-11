#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	map<char, int> mp;
	string s;
	cin >> s;
	for(char c : s) {
		mp[tolower(c)]++;
	}
	int mx=0;
	char ans=' ';
	for(auto it=mp.begin(); it!=mp.end(); ++it) {
		if(it->second>mx) {
			mx=it->second;
		}
	}
	int cnt=0;
	for(auto it=mp.begin(); it!=mp.end(); ++it) {
		if(it->second==mx) {
			++cnt;
			ans=it->first;
		}
	}
	cout << (cnt==1 ? (char)toupper(ans) : '?') << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
