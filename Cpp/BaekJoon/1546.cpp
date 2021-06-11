#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto& i : a)
		cin >> i;
	int m=*max_element(a.begin(), a.end());
	double sum=0;
	for(auto& i : a) {
		sum+=(double)i/m * 100;
	}
	cout.precision(18);
	cout << sum/a.size() << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
