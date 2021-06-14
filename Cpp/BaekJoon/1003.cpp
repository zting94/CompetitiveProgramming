#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int ones[41];
int zeros[41];

void fibo(int n) {
	if(n==0) {
		ones[0]=0;
		zeros[0]=1;
		return;
	} else if(n==1) {
		ones[1]=1;
		zeros[1]=0;
		return;
	}
	if(ones[n]!=-1&&zeros[n]!=-1) {
		return;
	}
	zeros[n]=ones[n]=0;
	fibo(n-1);
	fibo(n-2);
	ones[n]=ones[n-1]+ones[n-2];
	zeros[n]=zeros[n-1]+zeros[n-2];
}

void solve() {
	int n;
	cin >> n;
	cout << zeros[n] << ' ' << ones[n] << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	memset(ones, -1, sizeof(ones));
	memset(zeros, -1, sizeof(zeros));

	fibo(40);

	int tt;
	cin >> tt;
	while(tt--) {
    	solve();
	}

    return 0;
}
