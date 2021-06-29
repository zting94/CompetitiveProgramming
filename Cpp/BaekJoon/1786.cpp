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

string a, b;
vector<int> pi;
int n, m;

void fail() {
	int j=0;
	for(int i=1; i<m; ++i) {
		while(j>0&&b[i]!=b[j])
			j=pi[j-1];
		if(b[i]==b[j])
			pi[i]=++j;
	}
}

vector<int> kmp() {
	vector<int> ans;
	int j=0;
	for(int i=0; i<n; ++i) {
		while(j>0&&a[i]!=b[j])
			j=pi[j-1];
		if(a[i]==b[j]) {
			++j;
			if(j==m) {
				ans.push_back(i-m+1);
				j=pi[j-1];
			}
		}
	}
	return ans;
}

void solve() {
	getline(cin, a);
	getline(cin, b);
	n=a.size();
	m=b.size();
	vector<int> pi(m, 0);
	for(int i=1, j=0; i<m; ++i) {
		while(j>0&&b[i]!=b[j])
			j=pi[j-1];
		if(b[i]==b[j])
			pi[i]=++j;
	}
	vector<int> ans;
	for(int i=0, j=0; i<n; ++i) {
		while(j>0&&a[i]!=b[j])
			j=pi[j-1];
		if(a[i]==b[j]) {
			++j;
			if(j==m) {
				ans.push_back(i-m+2);
				j=pi[j-1];
			}
		}
	}
	print(ans.size());
	if(ans.size())
		print(ans);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
