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

const int mxK=1e5;
bool vis[mxK+1];

void solve() {
	int n, k;
	cin >> n >> k;
	int ans=0;
	unordered_map<int, int> v[2];
	v[0][n]=1;
	for(int i=1; i<=mxK+2; ++i) {
		int j=(i-1)%2, l=i%2;
		for(auto& [val, cnt] : v[j]) {
			if(val<0||val>mxK||vis[val])
				continue;
			vis[val]=true;
			ans+=(val==k?cnt:0);
			v[l][val-1]+=cnt;
			v[l][val+1]+=cnt;
			v[l][val*2]+=cnt;
		}
		if(ans) {
			print(i-1);
			print(ans);
			return;
		}
		v[j].clear();
	}
	assert(false);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
