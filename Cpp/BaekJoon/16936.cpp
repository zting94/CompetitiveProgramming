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

set<ll> s, vis;
const int mxN=101;
bool done;
int n;

void dfs(vl& vt, ll last) {
	if(done||vis.find(last)!=vis.end())
		return;
	if(vt.size()==n) {
		print(vt);
		done=true;
		return;
	}
	vis.insert(last);
	if((last%3==0)&&(s.find(last/3)!=s.end())) {
		vt.push_back(last/3);
		dfs(vt, last/3);
		vt.pop_back();
	}
	if(s.find(last*2)!=s.end()) {
		vt.push_back(last*2);
		dfs(vt, last*2);
		vt.pop_back();
	}
	vis.erase(last);
}

void solve() {
	done=false;
	cin >> n;
	ll a;
	for(int i=0; i<n; ++i) {
		cin >> a;
		s.insert(a);
	}
	vl vt;
	for(ll i : s) {
		if(done)
			break;
		vt.push_back(i);
		dfs(vt, i);
		vt.pop_back();
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
