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
	long long sum = 0;
	int maxV = 0;
	FOR(n) {
		cin >> arr[i];
		sum += arr[i];
		maxV = max(maxV, arr[i]);
	}
	long long k = max((long long)ceil((double)sum / (n - 1)), (long long)maxV);
	cout << (n - 1) * k - sum << NL;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCase = 1;
    cin >> testCase;
    for(int t = 0; t < testCase; ++t) 
       solve();

    return 0;
}