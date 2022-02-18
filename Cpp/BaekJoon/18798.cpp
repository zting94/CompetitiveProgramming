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
const int mxN=25e4+1;
int N, K, M, A[mxN], tree[mxN*4], fen[mxN+1];

void Upd(int x, int v) {
	for(int i=x+1; i<mxN; i+=(i&-i))
		fen[i]+=v;
}

int Sum(int x) {
	int ret=0;
	for(int i=x+1; i>0; i-=(i&-i))
		ret+=fen[i];
	return ret;
}

int init(int i, int s, int e) {
	if(s==e) {
		if(A[s]==K)
			Upd(s, 1);
		return tree[i]=A[s];
	}
	int m=(s+e)/2;
	return tree[i]=init(i*2, s, m)&init(i*2+1, m+1, e);
}

int update(int i, int s, int e, int l, int r, int v) {
	//if(e<l||r<s||((tree[i]|v)==tree[i]))
	if(e<l||r<s||(tree[i]&v)==v)
		return tree[i];
	if(s==e) {
		if(tree[i]==K)
			Upd(s, -1);
		tree[i]|=v;
		if(tree[i]==K)
			Upd(s, 1);
		return tree[i];
	}
	int m=(s+e)/2;
	return tree[i]=update(i*2, s, m, l, r, v)&update(i*2+1, m+1, e, l, r, v);
}

void solve() {
	cin >> N >> K;
	read(A, N);
	init(1, 0, N-1);
	cin >> M;
	while(M--) {
		int c, l, r, v;
		cin >> c >> l >> r, --l, --r;
		if(c==1) {
			cin >> v;
			update(1, 0, N-1, l, r, v);
		} else {
			print(Sum(r)-Sum(l-1));
		}
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
