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

const int mxN=1e4;
ll x[mxN], y[mxN];
int n;

ll ccw(int i, int j, int k) {
	//x1 x2 x3 x1
	//y1 y2 y3 y1
	ll a=(x[i]*y[j]+x[j]*y[k]+x[k]*y[i]);
	ll b=(x[j]*y[i]+x[k]*y[j]+x[i]*y[k]);
	return a-b;
}

ll ccw2(int i, int j, int k) {
	//(x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
	return (x[j]-x[i])*(y[k]-y[i])-(y[j]-y[i])*(x[k]-x[i]);
}

void solve() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> x[i] >> y[i];
	ll ans=0;
	for(int i=1; i<n-1; ++i) 
		ans+=ccw(0, i, i+1);
	print(fabs(ans)/2);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cout.precision(1);
	cout << fixed;

    solve();

    return 0;
}
