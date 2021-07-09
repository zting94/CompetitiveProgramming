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

const int mxN=1e7;
vector<bool> b;

void pre() {
	b=vector<bool>(mxN+1, true);
	b[0]=b[1]=false;
	for(int i=4; i<=mxN; i+=2)
		b[i]=false;
	for(int i=3; i*i<=mxN; i+=2) {
		if(b[i]) {
			for(int j=i+i; j<=mxN; j+=i) {
				b[j]=false;
			}
		}
	}
}

void solve() {
	string s;
	cin >> s;
	sort(all(s));
	map<int, bool> mp;
	int ans=0;
	do {
		for(int i=0; i<s.size(); ++i) {
			int v=stoi(s.substr(i));
			if(mp[v])
				continue;
			mp[v]=true;
			if(b[v])
				++ans;
		}
	} while(next_permutation(all(s)));
	print(ans);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	pre();

	int t;
	cin >> t;
	while(t--)
    	solve();

    return 0;
}
