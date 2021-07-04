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

int L, C;
vector<char> a;

int cnt1(int a, char c) {
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
		return a+1;
	return a;
}

int cnt2(int a, char c) {
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
		return a;
	return a+1;
}

void dfs(int i, string& s, int m, int j) {
	if(i+1==C||s.size()==L) {
		if(s.size()==L&&m>=1&&j>=2) 
			print(s);
		return;
	}
	for(int n=i+1; n<C; ++n) {
		s.push_back(a[n]);
		dfs(n, s, cnt1(m, a[n]), cnt2(j, a[n]));
		s.pop_back();
	}
}

void solve() {
	cin >> L >> C;
	a=vector<char>(C);
	read(a);
	sort(all(a));
	string s;
	dfs(-1, s, 0, 0);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
