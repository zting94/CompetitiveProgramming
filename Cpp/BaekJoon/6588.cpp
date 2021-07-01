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
void read(vector<T>& v) {
	for(auto& x : v)
		cin >> x;
}

template<typename T>
void read(vector<vector<T>>& v) {
	for(auto& a : v)
		read(a);
}

const int mxN=1e6+1;
int n;
bool pp[mxN];

void pre() {
	for(int i=2; i<=mxN; ++i) 
		pp[i]=(i&1)?true:false;
	for(int i=3; i<=mxN; i+=2) {
		if(pp[i]) {
			for(int j=i*2; j<=mxN; j+=i)
				pp[j]=false;
		}
	}
}

void solve() {
	for(int i=n-2; i>=0; --i) {
		if(pp[i]&&pp[n-i]) {
			cout << n << " = " << (n-i) << " + " << (i) << '\n';
			return;
		}
	}	
	assert(false);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	pre();

	while(true) {
		cin >> n;
		if(n==0)
			break;
		solve();
	}

    return 0;
}
