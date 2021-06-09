#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int N, K;
	cin >> N >> K;
	vector<int> arr(N);
	for(auto& i : arr)
		cin >> i;
	sort(arr.rbegin(), arr.rend());
	int ans = 0;
	for(int i = 0; i < N; ++i) {
		while(arr[i] <= K) {
			K -= arr[i];
			++ans;
		}
	}
	cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
