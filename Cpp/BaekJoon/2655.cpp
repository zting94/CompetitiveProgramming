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

class B {
public:
	int a, h, w, id;
};

const int mxN=101;
int dp[mxN], n, cur;
vector<B> a;
vi ans;

int dfs(int i) {
	if(i==n)
		return 0;
	int& ret=dp[i];
	if(ret!=-1)
		return ret;
	ret=a[i].h;
	for(int j=i+1; j<n; ++j)
		if(a[i].a<a[j].a&&a[i].w<a[j].w)
			ret=max(ret, dfs(j)+a[i].h);
	return ret;
}

void reconstruct(int i) {
	if(i==n||cur<=0||dp[i]==-1)
		return;
	if(i&&dp[i]==cur) {
		ans.push_back(a[i].id);
		cur-=a[i].h;
	}
	for(int j=i+1; j<n; ++j)
		if(a[i].a<=a[j].a&&a[i].w<=a[j].w)
			reconstruct(j);
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> n;
	a=vector<B>(n);
	for(int i=0; i<n; ++i) {
		B& b=a[i];
		cin >> b.a >> b.h >> b.w;
		b.id=i+1;
	}
	++n;
	a.insert(a.begin(), {0, 0, 0, 0});
	sort(all(a), [](auto& l, auto& r) {
		return l.a<r.a;
	});
	cur=dfs(0);
	reconstruct(0);
	print(ans.size());
	print(ans, '\n');
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
