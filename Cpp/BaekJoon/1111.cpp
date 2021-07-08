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
	int n;
	cin >> n;
	vi a(n);
	read(a);
	if(n==1) {
		print("A");
		return;
	} else if(n==2) {
		print(a[0]==a[1]?to_string(a[0]):"A");
		return;
	}
	if(a[0]==a[1]) {
		if(a[1]!=a[2]) {
			print("B");
			return;
		}
	} else if((a[2]-a[1])%(a[1]-a[0])) {
		print("B");
		return;
	}
	int A=(a[1]==a[0])?1:(a[2]-a[1])/(a[1]-a[0]);
	int B=(a[1]==a[0])?0:a[1]-A*a[0];
	for(int i=0; i<n-1; ++i) {
		if(a[i+1]!=a[i]*A+B) {
			print("B");
			return;
		}
	}
	print(A*a[n-1]+B);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
