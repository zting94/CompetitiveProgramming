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
	vector<string> s(n);
	read(s);
	vvi p(n, vi(5));
	for(int i=0; i<n; ++i) 
		for(char c : s[i])
			p[i][c-'a']++;
	int ans=0;
	for(int k=0; k<5; ++k) {
		vi val;
		for(int i=0; i<n; ++i) {
			int sum=0;
			for(int j=0; j<5; ++j) {
				if(j==k)
					sum+=p[i][j];
				else
					sum-=p[i][j];
			}
			val.push_back(sum);
		}
		sort(rall(val));
		int sum=0, cur=0;
		for(int i : val) {
			sum+=i;
			if(sum>0)
				++cur;
			else
				break;
		}
		ans=max(ans, cur);
	}
	print(ans);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while(tt--) {
    	solve();
    }

    return 0;
}
