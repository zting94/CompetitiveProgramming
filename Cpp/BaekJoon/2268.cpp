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

const int mxN=1e6;
int N, M;
ll tree[mxN*4];

ll update(int node, int s, int e, int i, int k) {
	if(s>i||e<i)
		return tree[node];
	if(i<=s&&e<=i)
		return tree[node]=k;
	int m=(s+e)/2;
	return tree[node]=update(node*2, s, m, i, k)+update(node*2+1, m+1, e, i, k);
}

ll query(int node, int s, int e, int l, int r) {
	if(r<s||e<l)
		return 0;
	if(l<=s&&e<=r)
		return tree[node];
	int m=(s+e)/2;
	return query(node*2, s, m, l, r)+query(node*2+1, m+1, e, l, r);
}

void solve() {
	cin >> N >> M;
	for(int i=0; i<M; ++i) {
		int c, a, b;
		cin >> c >> a >> b;
		if(c==0) {
			print(query(1, 0, N-1, min(a-1, b-1), max(a-1, b-1)));
		} else {
			update(1, 0, N-1, a-1, b);
		}
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
