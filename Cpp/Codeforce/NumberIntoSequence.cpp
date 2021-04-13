#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(int i = 0; i < int(n); ++i)
#define RFOR(n) for(int i = int(n); ~i; --i)
#define FORI(i, n) for(int i = 0; i < int(n); ++i)
#define NL '\n'

vector<long long> primes;

void precalc() {
	long long n = sqrt((long long)1e10);
	primes.push_back(2);
	for(long long i = 3; i <= n; ++i) {
		int cnt = 0;
		for(long long j = 2; j < i; ++j) {
			if(i % j == 0) {
				++cnt;
				break;
			}
		}
		if(cnt == 0)
			primes.push_back(i);
	}
}

void solve() {
	long long n;
	cin >> n;
	long long maxCnt = 1;
	long long prime = 1;
	long long sq = sqrt(n);
	long long tmp = n;
	for(int i = 0; i < primes.size(); ++i) {
		if(primes[i] > sq)
			break;
		long long cnt = 0;
		while(tmp % primes[i] == 0) {
			++cnt;
			tmp /= primes[i];
		}
		if(cnt > maxCnt) {
			prime = primes[i];
			maxCnt = cnt;
		}
	}
	cout << maxCnt << NL;
	for(int i = 0; i < maxCnt - 1; ++i)
		cout << prime << ' ';
	cout << ((long long)n / (long long)pow((long long)prime, (long long)maxCnt - 1)) << NL;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCase = 1;
    cin >> testCase;
    precalc();
    for(int t = 0; t < testCase; ++t) 
       solve();

    return 0;
}