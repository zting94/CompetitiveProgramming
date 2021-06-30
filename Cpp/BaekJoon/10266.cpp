#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

template<typename T>
void print(const vector<vector<T>>& v, char sp=' ') {
	int n=v.size();
	if(n==0)
		return;
	int m=v[0].size();
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			if(j>0)
				cout << sp;
			cout << v[i][j];
		}
		cout << '\n';
	}
}

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
void print(T v) {
	cout << v << '\n';
}

template<typename T>
void read(vector<vector<T>>& v) {
	for(auto& a : v)
		for(auto& i : a)
			cin >> i;
}

template<typename T>
void read(vector<T>& v) {
	for(auto& x : v)
		cin >> x;
}

const int M=360000;
string a, b;
int n;
vector<int> pi;

void fail() {
	pi=vector<int>(b.size(), 0);
	for(int i=1, j=0; i<b.size(); ++i) {
		while(j&&b[i]!=b[j])
			j=pi[j-1];
		if(b[i]==b[j])
			pi[i]=++j;
	}
}

bool kmp() {
	for(int i=0, j=0; i<a.size(); ++i) {
		while(j&&a[i]!=b[j])
			j=pi[j-1];
		if(a[i]==b[j]) {
			++j;
			if(j==b.size())
				return true;
		}
	}
	return false;
}

void solve() {
	cin >> n;
	a=string(M, '0');
	b=string(M, '0');
	int t;
	//really tricky
	for(int i=0; i<n; ++i) {
		cin >> t;
		a[t]='1';
	}
	for(int i=0; i<n; ++i) {
		cin >> t;
		b[t]='1';
	}
	a+=a;
	fail();
	print(kmp()?"possible":"impossible");
}


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
