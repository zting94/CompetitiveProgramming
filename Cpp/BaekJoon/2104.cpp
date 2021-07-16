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

const int mxN=1e5;
int N, a[mxN+3], tree[mxN*4];
ll sum[mxN+2];

int init(int i, int s, int e) {
	if(s==e) 
		return tree[i]=s;
	int m=(s+e)/2;
	int l=init(i*2, s, m);
	int r=init(i*2+1, m+1, e);
	//i*2로 써서 한시간 날림-_-
	return tree[i]=(a[l]<a[r]?l:r);
}

int query(int i, int s, int e, int l, int r) {
	if(e<l||r<s) 
		return N+1;
	if(l<=s&&e<=r)  
		return tree[i];
	int m=(s+e)/2;
	int lmin=query(i*2, s, m, l, r);
	int rmin=query(i*2+1, m+1, e, l, r);
	return a[lmin]<a[rmin]?lmin:rmin;
}

ll dfs(int l, int r) {
	if(l==r)
		return a[l]*1LL*a[l];
	if(l>r)
		return 0;

	int q=query(1, 0, N-1, l, r);
	ll ret=(sum[r+1]-sum[l])*a[q];
	ret=max(ret, dfs(l, q-1));
	ret=max(ret, dfs(q+1, r));

	return ret;
}

void solve() {
	cin >> N;
	read(a, N);
	a[N+1]=1e9;
	for(int i=0; i<N; ++i)
		sum[i+1]=sum[i]+a[i];
	init(1, 0, N-1);
	print(dfs(0, N-1));
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
