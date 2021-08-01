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
	int N;
	cin >> N;
	vector<string> s(N);
	read(s);
	vector<pair<ll, int>> cnt(10);
	vector<bool> first(10, false);
	int conv[10];
	for(int i=0; i<10; ++i)
		cnt[i].second=i;
	for(string& a : s) {
		int n=a.size()-1;
		for(int i=n; i>=0; --i) 
			cnt[a[i]-'A'].first+=pow(10, n-i+1);
		first[a[0]-'A']=true;
	}
	sort(rall(cnt));
	for(int i=0, j=9; i<10; ++i) 
		conv[cnt[i].second]=j--;
	for(int i=9; i>0; --i) {
		if(!first[cnt[i].second])
			break;
		swap(conv[cnt[i-1].second], conv[cnt[i].second]);
	}
	ll ans=0;
	for(string& a : s) {
		for(int i=0; i<a.size(); ++i)
			a[i]=conv[a[i]-'A']+'0';
		ans+=stoll(a);
	}
	print(ans);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
