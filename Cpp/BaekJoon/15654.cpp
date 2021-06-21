#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int n, m;
vector<int> a;
bool vis[8]={false,};

void pf(vector<int>& v) {
	for(auto& i:v)
		cout << i << ' ';
	cout << '\n';
}

void go(int i, vector<int>& v) {
	if(v.size()==m) {
		pf(v);
		return;
	}
	for(int next=0; next<n; ++next) {
		if(vis[next])
			continue;
		vis[next]=true;
		v.push_back(a[next]);
		go(next, v);
		v.pop_back();
		vis[next]=false;
	}
}

void solve() {
	cin >> n >> m;
	for(int i=0; i<n; ++i) {
		int v;
		cin >> v;
		a.push_back(v);
	}
	sort(a.begin(), a.end());
	vector<int> v;
	go(-1, v);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
