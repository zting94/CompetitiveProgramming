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
const int mxN=11;
int N, M, A[mxN][mxN];

bool root(ll v) {
	ll t=sqrt(v);
	return t*t==v;
}

void solve() {
	cin >> N >> M;
	for(int i=0; i<N; ++i) 
		for(int j=0; j<M; ++j) {
			char c;
			cin >> c;
			A[i][j]=c-'0';
		}
	ll ans=-1;
	for(int x=0; x<N; ++x) {
		for(int y=0; y<M; ++y) {
			for(int xoff=-N; xoff<=N; ++xoff) {
				for(int yoff=-M; yoff<=M; ++yoff) {
					if(xoff==0&&yoff==0)
						continue;
					ll v=0;
					int i=x, j=y;
					while(0<=i&&0<=j&&i<N&&j<M) {
						v=v*10+A[i][j];
						if(root(v))
							ans=max(ans, v);
						i+=xoff;
						j+=yoff;
					}
					if(root(v))
						ans=max(ans, v);
				}
			}
		}
	}
	print(ans);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
