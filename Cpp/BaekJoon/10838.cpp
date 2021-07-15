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

int N, K, TC;
vi par, check, col;

int LCA(int a, int b) {
	if(a==b)
		return a;
	for(int i=0; i<=1000; ++i) {
		check[a]=TC;
		if(par[a]==-1)
			break;
		a=par[a];
	}
	for(int i=0; i<=1000; ++i) {
		if(check[b]==TC) {
			return b;
		}
		if(par[b]==-1)
			break;
		b=par[b];
	}
	assert(b!=-1);
	return b;
}

void solve() {
	cin >> N >> K;
	par=vi(N+1);
	col=vi(N+1);
	check=vi(N+1);
	par[0]=-1;
	int r, a, b, cnt;
	for(TC=1; TC<=K; ++TC) {
		cin >> r >> a >> b;
		if(r==1) {
			cin >> cnt;
			int lca=LCA(a, b);
			while(a!=lca) {
				col[a]=cnt;
				a=par[a];
			}
			while(b!=lca) {
				col[b]=cnt;
				b=par[b];
			}
	 	} else if(r==2) {
			par[a]=b;
		} else {
			int lca=LCA(a, b);
			set<int> s;
			while(a!=lca) {
				s.insert(col[a]);
				a=par[a];
			}
			while(b!=lca) {
				s.insert(col[b]);
				b=par[b];
			}
			print(s.size());
		}
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
