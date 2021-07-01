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

void solve() {
	int n;
	cin >> n;
	vector<int> num(n+1, 0);
	for(int i=2; i<=n; i+=2)
		num[i]=2;
	for(int i=3; i<=n; i+=2) {
		if(num[i])
			continue;
		for(int j=i; j<=n; j+=i)
			num[j]=i;
	}
	vector<int> p;
	for(int i=2; i<=n; ++i)
		if(num[i]==i)
			p.push_back(i);
	int sum=0, ans=0;
	for(int l=0, r=0; r<p.size(); ++r) {
		sum+=p[r];
		while(sum>n) 
			sum-=p[l++];
		if(sum==n)
			++ans;
	}
	print(ans);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
