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
const int mxN=1e5+1;
int N, tree[mxN*4], ans[mxN];

int init(int i, int s, int e) {
	if(s==e) 
		return tree[i]=1;
	int m=(s+e)/2;
	return tree[i]=init(i*2, s, m)+init(i*2+1, m+1, e);
}

int query(int i, int s, int e, int k) {
	if(s==e)
		return s;
	int m=(s+e)/2;
	if(tree[i*2]>k) 
		return query(i*2, s, m, k);
	else 
		return query(i*2+1, m+1, e, k-tree[i*2]);
}

int update(int i, int s, int e, int k) {
	if(e<k||k<s)
		return tree[i];
	if(s==e)
		return tree[i]=0;
	int m=(s+e)/2;
	return tree[i]=update(i*2, s, m, k)+update(i*2+1, m+1, e, k);
}

void solve() {
	cin >> N;
	init(1, 0, N-1);
	for(int i=0, a; i<N; ++i) {
		cin >> a;
		int idx=query(1, 0, N-1, a);
		ans[idx]=i+1;
		update(1, 0, N-1, idx);
	}
	print(ans, N, nl);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
