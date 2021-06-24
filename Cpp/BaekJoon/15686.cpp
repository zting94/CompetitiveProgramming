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

int n, m;
int ans;
vector<vector<int>> a, d;
vector<pair<int, int>> h, c;

void dfs(int i, int mask, int k) {
	if(k==0) {
		int tmp=0;
		for(int i=0; i<h.size(); ++i) {
			int cur=INT_MAX;
			for(int j=0; j<c.size(); ++j) {
				if(mask&(1<<j)) {
					cur=min(cur, d[i][j]);
				}
			}
			tmp+=cur;
		}
		ans=min(ans, tmp);
		return;
	}
	if(i+1==c.size()) {
		return;
	}
	for(int j=i+1; j<c.size(); ++j) {
		if(mask&(1<<j))
			continue;
		dfs(j, mask|(1<<j), k-1);
	}
}

void solve() {
	cin >> n >> m;
	a=vector<vector<int>>(n, vector<int>(n));
	for(int i=0; i<n; ++i) 
		for(int j=0; j<n; ++j) {
			cin >> a[i][j];
			if(a[i][j]==1)
				h.push_back({i, j});
			else if(a[i][j]==2)
				c.push_back({i, j});
		}
	d=vector<vector<int>>(h.size(), vector<int>(c.size()));
	for(int i=0; i<h.size(); ++i)  
		for(int j=0; j<c.size(); ++j) 
			d[i][j]=abs(h[i].first-c[j].first)+abs(h[i].second-c[j].second);
	ans=INT_MAX;
	dfs(-1, 0, m);
	print(ans);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
