#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

string a, b;
int n, m;

void print(const vector<int>& v) {
	for(auto i : v)
		cout << i << ' ';
	cout << '\n';
}

vector<int> fail1() {
	vector<int> pi(m, 0);
	int j=0;
	for(int i=1; i<m; ++i) {
		while(j>0&&b[i]!=b[j])
			j=pi[j-1];
		if(b[i]==b[j])
			pi[i]=++j;
	}
	return pi;
}

vector<int> kmp1() {
	vector<int> pos;
	vector<int> pi=fail1();
	int j=0;
	for(int i=0; i<n; ++i) {
		while(j>0&&a[i]!=b[j])
			j=pi[j-1];
		if(a[i]==b[j]) {
			++j;
			if(j==m) {
				pos.push_back(i-m+1);
				j=pi[j-1];
			}
		}
	}
	return pos;
}

vector<int> fail2() {
	vector<int> pi(m, 0);
	int i=1, j=0;
	while(i+j<m) {
		if(b[i+j]==b[j]) {
			++j;
			pi[i+j-1]=j;
		} else {
			if(j==0)
				++i;
			else {
				i+=j-pi[j-1];
				j=pi[j-1];
			}
		}
	}
	return pi;
}

vector<int> kmp2() {
	vector<int> pos;
	vector<int> pi=fail2();
	int i=0, j=0;
	while(i+m<=n) {
		if(j<m&&a[i+j]==b[j]) {
			++j;
			if(j==m)
				pos.push_back(i);
		} else {
			if(j==0)
				++i;
			else {
				i+=j-pi[j-1];
				j=pi[j-1];
			}
		}
	}

	return pos;
}

void solve() {
	cin >> a >> b;
	n=a.size();
	m=b.size();
	auto f1=fail1();
	auto f2=fail2();
	assert(f1==f2);

	auto k1=kmp1();
	auto k2=kmp2();
	assert(k1==k2);
	print(f1);
	print(f2);
	print(k1);
	print(k2);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
