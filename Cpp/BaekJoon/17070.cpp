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

const int mxN=16;
int a[mxN][mxN];
int dp[mxN+1][mxN+1][3];

void solve() {
	memset(dp, 0, sizeof(dp));
	int n;
	cin >> n;
	for(int i=0; i<n; ++i) 
		for(int j=0; j<n; ++j)
			cin >> a[i][j];
	dp[0][1][0]=1;
	//0=가로
	//1=세로
	//2=대각
	auto diag=[&](int i, int j) {
		return i>0&&j>0&&a[i-1][j]==0&&a[i][j-1]==0;
	};
	auto ver=[&](int i, int j) {
		return i>0&&a[i-1][j]==0;
	};
	auto hor=[&](int i, int j) {
		return j>0&&a[i][j-1]==0;
	};
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			if(a[i][j])
				continue;
			if(hor(i, j)) {
				dp[i][j][0]+=dp[i][j-1][0];
				dp[i][j][0]+=dp[i][j-1][2];
			}
			if(ver(i, j)) {
				dp[i][j][1]+=dp[i-1][j][1];
				dp[i][j][1]+=dp[i-1][j][2];
			}
			if(diag(i, j)) {
				for(int k=0; k<3; ++k)
					dp[i][j][2]+=dp[i-1][j-1][k];
			}
		}
	}
	int ans=0;
	for(int i=0; i<3; ++i)
		ans+=dp[n-1][n-1][i];
	print(ans);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
