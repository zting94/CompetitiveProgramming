#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int n;
	cin >> n;
	if(n>=90)
		cout << "A\n";
	else if(n>=80)
		cout << "B\n";
	else if(n>=70)
		cout << "C\n";
	else if(n>=60)
		cout << "D\n";
	else
		cout << "F\n";
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
