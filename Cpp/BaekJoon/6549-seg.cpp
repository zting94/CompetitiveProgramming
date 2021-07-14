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
int N, a[mxN+1], tree[mxN*4];
ll ans;

int minIndex(int i, int j) {
	return a[i]<a[j]?i:j;
}

int init(int node, int s, int e) {
	if(s==e) 
		return tree[node]=s;
	int m=(s+e)/2;
	int l=init(node*2, s, m);
	int r=init(node*2+1, m+1, e);
	return tree[node]=minIndex(l, r);
}

int query(int node, int s, int e, int l, int r) {
	if(e<l||r<s)
		return -1;
	if(l<=s&&e<=r)
		return tree[node];
	int m=(s+e)/2;
	int lm=query(node*2, s, m, l, r);
	int rm=query(node*2+1, m+1, e, l, r);
	if(lm==-1)
		return rm;
	else if(rm==-1)
		return lm;
	return minIndex(lm, rm);
}

ll calc(int s, int e) {
	if(s==e)
		return a[s];
	int m=query(1, 0, N-1, s, e);
	assert(m!=-1);
	ll ret=a[m]*1LL*(e-s+1);
	if(s<m) 
		ret=max(ret, calc(s, m-1));
	if(m<e) 
		ret=max(ret, calc(m+1, e));
	return ret;
}

void solve() {
	read(a, N);
	init(1, 0, N-1);
	print(calc(0, N-1));
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	while(1) {
		cin >> N;
		if(N==0)
			break;
		solve();
	}

    return 0;
}
