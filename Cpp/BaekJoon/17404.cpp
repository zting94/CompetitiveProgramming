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

const int mxN=1000;
const int mx=1e8;
const int M=3;
int N;

void solve() {
	cin >> N;
	vector<array<int, 3>> a(N);
	for(int i=0; i<N; ++i)
		for(int j=0; j<3; ++j)
			cin >> a[i][j];
	int ans=mx;
	for(int k=0; k<3; ++k) {
		vector<array<int, 3>> dp(N, array<int, 3>{mx,mx,mx});
		for(int i=0; i<3; ++i) {
			if(i==k)
				dp[0][i]=a[0][i];
		}
		for(int i=1; i<N; ++i) {
			for(int j=0; j<3; ++j) {
				dp[i][j]=min(dp[i-1][(j-1+M)%M], dp[i-1][(j+1)%M])+a[i][j];
			}
		}
		for(int i=0; i<3; ++i)
			if(i!=k)
				ans=min(ans, dp[N-1][i]);
	}
	print(ans);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
