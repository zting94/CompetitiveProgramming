#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

template<typename T>
void print(const vector<vector<T>>& v, char sp=' ') {
	int n=v.size();
	if(n==0)
		return;
	int m=v[0].size();
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			if(j>0)
				cout << sp;
			cout << v[i][j];
		}
		cout << '\n';
	}
}

template<typename T>
void print(const vector<T>& v, char sp=' ') {
	for(int i=0; i<v.size(); ++i) {
		if(i>0)
			cout << sp;
		cout << v[i];
	}
	cout << '\n';
}

template<typename T>
void print(T v) {
	cout << v << '\n';
}

template<typename T>
void read(vector<vector<T>>& v) {
	for(auto& a : v)
		for(auto& i : a)
			cin >> i;
}

template<typename T>
void read(vector<T>& v) {
	for(auto& x : v)
		cin >> x;
}

const int mxN=1e5+1;
const int mx=1e8;
vector<int> a;
int cache[mxN][5][5];
int n;

int step(int s, int e) {
	if(s==0)
		return 2;
	if(s==e)
		return 1;
	if(abs(s-e)==2)
		return 4;
	return 3;
}

int dp(int l, int r, int i) {
	if(i==n)
		return 0;
	int& ret=cache[i][l][r];
	if(ret!=-1)
		return ret;
	return ret=min(dp(a[i], r, i+1)+step(l, a[i]), dp(l, a[i], i+1)+step(r, a[i]));
}

void solve() {
	while(true) {
		int i;
		cin >> i;
		if(i==0)
			break;
		a.push_back(i);
	}
	n=a.size();
	memset(cache, -1, sizeof(cache));
	print(dp(0, 0, 0));
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
