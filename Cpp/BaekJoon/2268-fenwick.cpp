#include <bits/stdc++.h>

/*∆Ê¿® ∆Æ∏Æ¥¬ diff ∏∏≈≠ update∏¶ «ÿ¡‡æﬂ «‘¥œ¥Á*/

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

const int mxN=1e6;
int N, M;
ll tree[mxN+1], A[mxN+1];

void update(int i, int k) {
	while(i<=N) {
		tree[i]+=k;
		i+=(i&-i);
	}
}

ll query(int i) {
	ll ret=0;
	while(i) {
		ret+=tree[i];
		i-=(i&-i);
	}
	return ret;
}

ll sum(int l, int r) {
	if(l>r)
		swap(l, r);
	return query(r)-query(l-1);
}

void solve() {
	cin >> N >> M;
	for(int i=0; i<M; ++i) {
		int c, a, b;
		cin >> c >> a >> b;
		if(c==0) {
			print(sum(a, b));
		} else {
			update(a, b-A[a]);
			A[a]=b;
		}
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
