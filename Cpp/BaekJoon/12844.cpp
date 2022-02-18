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
const int mxN=5e5+1;
int N, M, A[mxN], tree[mxN*4], lazy[mxN*4];

int init(int i, int s, int e) {
	if(s==e)
		return tree[i]=A[s];
	int m=(s+e)/2;
	return tree[i]=init(i*2, s, m)^init(i*2+1, m+1, e);
}

void prop(int i, int s, int e) {
	if(!lazy[i])
		return;
	if((e-s+1)&1)
		tree[i]^=lazy[i];
	if(s!=e) {
		lazy[i*2]^=lazy[i];
		lazy[i*2+1]^=lazy[i];
	}
	lazy[i]=0;
}

int update(int i, int s, int e, int l, int r, int v) {
	prop(i, s, e);
	if(e<l||r<s)
		return tree[i];
	if(l<=s&&e<=r) {
		lazy[i]=v;
		prop(i, s, e);
		return tree[i];
	}
	int m=(s+e)/2;
	return tree[i]=update(i*2, s, m, l, r, v)^update(i*2+1, m+1, e, l, r, v);
}

int query(int i, int s, int e, int l, int r) {
	prop(i, s, e);
	if(e<l||r<s)
		return 0;
	if(l<=s&&e<=r)
		return tree[i];
	int m=(s+e)/2;
	return query(i*2, s, m, l, r)^query(i*2+1, m+1, e, l, r);
}

void solve() {
	cin >> N;
	read(A, N);
	init(1, 0, N-1);
	cin >> M;
	while(M--) {
		int c, l, r, v;
		cin >> c >> l >> r;
		if(c==1) {
			cin >> v;
			update(1, 0, N-1, l, r, v);
		} else {
			print(query(1, 0, N-1, l, r));
		}
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
