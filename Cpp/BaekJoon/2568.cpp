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

const int mxN=5e5+1;
int n, m;

void solve() {
	vector<int> a(mxN, -1);
	n=0;
	cin >> m;
	for(int i=0; i<m; ++i) {
		int j, v;
		cin >> j >> v, --v;
		a[v]=j;
		n=max(n, v+1);
	}
	vector<int> dp(n+1, -1);
	vector<int> lis{-1};
	for(int i=0; i<n; ++i) {
		if(a[i]>lis.back()) {
			lis.push_back(a[i]);
			dp[i]=lis.size()-1;
		} else {
			int idx=lower_bound(lis.begin(), lis.end(), a[i])-lis.begin();
			lis[idx]=a[i];
			dp[i]=idx;
		}
	}
	int cnt=lis.size()-1;
	vector<int> ans;
	for(int i=n-1; i>=0; --i) {
		if(cnt>0&&dp[i]==cnt) {
			--cnt;
		} else if(a[i]!=-1) {
			ans.push_back(a[i]);
		}
	}
	sort(ans.begin(), ans.end());
	print(ans.size());
	print(ans, '\n');
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
