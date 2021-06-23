#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int mxN=1e5+1;
int in[mxN], post[mxN], idx[mxN];
int n;
unordered_map<int, int> mp;

void pre(int is, int ie, int ps, int pe) {
	if(ps>pe)
		return;
	cout << post[pe] << ' ';
	int i=idx[post[pe]];
	pre(is, i-1, ps, ps+i-1-is);
	pre(i+1, ie, ps+i-is, pe-1);
}

void solve() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> in[i];
	for(int i=0; i<n; ++i) 
		cin >> post[i];
	for(int i=0; i<n; ++i)
		idx[in[i]]=i;
	pre(0, n-1, 0, n-1);
	cout << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
