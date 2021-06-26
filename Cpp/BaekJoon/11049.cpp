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

const int mxN=501;
int cache[mxN][mxN];
int R[mxN], C[mxN];
int N;

int dp(int s, int e) {
	if(s>=e)
		return 0;
	if(s+1==e) {
		assert(C[s]==R[e]);
		return R[s]*C[s]*C[e];
	}
	int& ret=cache[s][e];
	if(ret!=-1)
		return ret;
	ret=INT_MAX;
	for(int i=s; i<=e; ++i) 
		ret=min(ret, dp(s, i)+R[s]*C[i]*C[e]+dp(i+1, e));
	return ret;
}

void solve() {
	cin >> N;
	for(int i=0; i<N; ++i) 
		cin >> R[i] >> C[i];
	memset(cache, -1, sizeof(cache));
	print(dp(0, N-1));
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
