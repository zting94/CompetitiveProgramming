
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

const int mxN=1e6+1;
vector<int> cache;
int ms;

int dfs(int n) {
	if(n<=1) 
		return 0;
	int& ret=cache[n];
	if(ret!=-1)
		return ret;
	ret=dfs(n-1)+1;
	if(n%3==0)
		ret=min(ret, dfs(n/3)+1);
	if(n%2==0)
		ret=min(ret, dfs(n/2)+1);
	return ret;
}

void track(int n) {
	if(n<1||cache[n]>ms)
		return;
	if(cache[n]==ms) {
		cout << n << ' ';
		--ms;
	}
	track(n-1);
	if(n%3==0)
		track(n/3);
	if(n%2==0)
		track(n/2);
}

void solve() {
	int n;
	cin >> n;
	cache=vector<int>(n+1, -1);
	ms=dfs(n);
	cache[1]=0;
	print(ms);
	track(n);
	cout << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
