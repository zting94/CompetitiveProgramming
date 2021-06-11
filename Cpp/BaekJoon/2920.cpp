#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	vector<int> a(8);
	for(auto& i : a)
		cin >> i;
	bool as=true, ds=true;
	for(int i=0; i<7; ++i) {
		if(a[i]>a[i+1])
			as=false;
		if(a[i]<a[i+1])
			ds=false;
	}
	if(as)
		cout << "ascending\n";
	else if(ds)
		cout << "descending\n";
	else
		cout << "mixed\n";
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
