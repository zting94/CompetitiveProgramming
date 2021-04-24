#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(int i = 0; i < int(n); ++i)
#define RFOR(n) for(int i = int(n); ~i; --i)
#define FORI(i, n) for(int i = 0; i < int(n); ++i)
#define NL '\n'

vector<int> answer;
int inputCount;
int n;

void solve() {
	cin >> n >> inputCount;
	int maxCount = n * (n + 1) / 2 - 1;
	if(inputCount > maxCount || inputCount < (n - 1)) {
		cout << "IMPOSSIBLE\n";
		return;
	}
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