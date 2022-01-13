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

class Ptr {
public :
	int x, y, r, i;
};

const int dx[4]={-1, 0, 1, 0}, dy[4]={0, -1, 0, 1};
const int mxN=3e3+1;
int N, par[mxN];

int find(int a) {
	if(par[a]==a)
		return a;
	return par[a]=find(par[a]);
}

bool same(int a, int b) {
	return find(a)==find(b);
}

void merge(int a, int b) {
	par[find(a)]=find(b);
}

bool reach(Ptr& a, Ptr& b) {
	double d=sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
	return a.r+b.r>=d;
}

void solve() {
	cin >> N;
	vector<Ptr> A(N);
	for(int i=0; i<N; ++i) {
		auto& p=A[i];
		cin >> p.x >> p.y >> p.r;
		p.i=i;
		par[i]=i;
	}
	sort(all(A), [](auto& a, auto& b) {
		return a.x<b.x;
	});
	for(int i=0; i<N; ++i) {
		for(int j=i+1; j<N; ++j) {
			if(reach(A[i], A[j])) {
				merge(i, j);
			}
		}
	}
	int ans=0;
	set<int> s;
	for(int i=0; i<N; ++i) {
		int p=find(i);
		if(s.find(p)==s.end()) {
			++ans;
			s.insert(p);
		}
	}
	print(ans);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int tt;
	cin >> tt;
	while(tt--)
		solve();

    return 0;
}
