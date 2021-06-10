#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int M = 8;

void solve() {
	int N;
	cin >> N;
	vector<string> a(N);
	for(auto& i : a)
		cin >> i;
	int cnt[26] = {0, };
	for(auto& s : a) {
		int n = s.size();
		for(int i = n - 1; i >= 0; --i) {
			cnt[s[i] - 'A'] += pow(10, (n - i));
		}
	}
	vector<char> alphas;
	for(int i = 0; i < 26; ++i)
		if(cnt[i])
			alphas.push_back('A' + i);
	sort(alphas.begin(), alphas.end(), [&](auto& l, auto& r) {
		return cnt[l - 'A'] > cnt[r - 'A'];
	});
	int v = 9;
	unordered_map<char, char> mp;
	for(auto c : alphas) 
		mp[c] = '0' + v--;

	int ans = 0;
	for(auto& s : a) {
		transform(s.begin(), s.end(), s.begin(), [&](auto c) {
			return mp[c];
		});
		ans += stoi(s);
	}
	cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
