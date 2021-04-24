#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(int i = 0; i < int(n); ++i)
#define RFOR(n) for(int i = int(n); ~i; --i)
#define FORI(i, n) for(int i = 0; i < int(n); ++i)
#define NL '\n'

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	FOR(n)
		cin >> arr[i];
	int ans = 0;
	FOR(n - 1) {
		int minIdx = i;
		for(int j = i + 1; j < n; ++j) {
			if(arr[j] < arr[minIdx]) {
				minIdx = j;
			}
		}
		ans += (minIdx - i + 1);
		reverse(arr.begin() + i, arr.begin() + minIdx + 1);
	}
	cout << ans << NL;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCase = 1;
    cin >> testCase;
    for(int t = 1; t <= testCase; ++t) {
    	cout << "Case #" << t << ": ";
    	solve();
    }

    return 0;
}