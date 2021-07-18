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

void solve() {
	int N;
	cin >> N;
	vi L(N), R(N), C(N);
	read(C);
	for(int i=0; i<N; ++i) {
		int l=0;
		for(int j=0; j<i; ++j)
			l=max(l, R[j]-abs(C[i]-C[j]));
		L[i]=l;
		R[i]=l+C[i]*2;
	}
	for(int i=0; i<N; ++i) {
		int l=L[i], r=R[i];
		for(int j=0; j<i; ++j) 
			if(C[j]>C[i])
				l=max(R[j], l);
		for(int j=i+1; j<N; ++j)
			if(C[j]>C[i])
				r=min(L[j], r);
		if(l<r)
			cout << i+1 << ' ';
	}
	cout << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
