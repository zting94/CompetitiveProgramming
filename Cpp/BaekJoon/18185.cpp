#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vii = vector<pii>;
using vll = vector<pll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define nl '\n'

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
void print(const vector<vector<T>>& v, char sp=' ') {
	for(auto& vv : v)
		print(vv, sp);
}

template<typename T>
void print(T v) {
	cout << v << '\n';
}

template<typename T>
void print(T v[], int sz, char sp=' ') {
	for(int i=0; i<sz; ++i) {
		if(i>0)
			cout << sp;
		cout << v[i];
	}
	cout << '\n';
}

template<typename T>
void read(vector<T>& v) {
	for(auto& x : v)
		cin >> x;
}

template<typename T>
void read(vector<vector<T>>& v) {
	for(auto& a : v)
		read(a);
}

template<typename T>
void read(T a[], int sz) {
	for(int i=0; i<sz; ++i)
		cin >> a[i];
}

const int dx[4]={-1, 0, 1, 0}, dy[4]={0, -1, 0, 1};
const int mxN=1e4+5;
int N, A[mxN];
ll ans;

/*
2 1 2 > 1 0 1 > 0 0 1 > 0 0 0 = 7 + 3 + 3 = 13
2 1 2 > 1 0 2 > 0 0 2 > 0 0 0 = 5 + 3 + 3 + 3 = 14
*/

void solve() {
	cin >> N;
	read(A, N);
	for(int i=0; i<N; ++i) {
		if(A[i+1]<=A[i+2]) {
			int v=min(A[i], A[i+1]);
			ans+=v*7;
			A[i]-=v;
			A[i+1]-=v;
			A[i+2]-=v;
			v=min(A[i], A[i+1]);
			ans+=v*5;
			A[i]-=v;
			A[i+1]-=v;
		} else if(A[i+1]>A[i+2]) {
			int v=min(A[i], A[i+1]-A[i+2]);
			ans+=v*5;
			A[i]-=v;
			A[i+1]-=v;
			v=min(A[i], min(A[i+1], A[i+2]));
			ans+=v*7;
			A[i]-=v;
			A[i+1]-=v;
			A[i+2]-=v;
		}
		ans+=3*A[i];
	}
	print(ans);
}

/*
4 3 1 > 3 2 0 > 1 0 0 > 0 0 0 = 7 + 5*2 + 3 = 21
4 3 1 > 1 0 1 > 0 0 1 > 0 0 0 = 5*3 + 3 + 3 = 21

4 3 1 1 > 3 2 0 1 > 1 0 0 1 > 0 0 0 1 > 0 0 0 0 = 7 + 5*2 + 3 + 3 = 23
4 3 1 1 > 1 0 1 1 > 0 0 1 1 > 0 0 0 0 = 5*3 + 3 + 5 = 23
4 3 1 1 > 2 1 1 1 > 1 0 0 1 > 0 0 0 1 > 0 0 0 0 = 5*2 + 7 + 3 + 3 = 23
*/

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
