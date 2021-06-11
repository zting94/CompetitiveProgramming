#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
	int a,b;
	cin >> a >> b;
	if(a<b)
		cout<<"<\n";
	else if(b<a)
		cout << ">\n";
	else
		cout << "==\n";
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
