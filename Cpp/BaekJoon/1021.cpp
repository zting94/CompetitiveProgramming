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
	int N, M, ans=0;
	cin >> N >> M;
	deque<int> q;
	for(int i=1; i<=N; ++i)
		q.push_back(i);
	for(int i=0, a; i<M; ++i) {
		cin >> a;
		int ldist=0, d=0;
		for(int j=0; j<q.size(); ++j) {
			if(q.front()==a)
				ldist=d;
			++d;
			q.push_back(q.front());
			q.pop_front();
		}
		int rdist=q.size()-ldist;
		ans+=min(ldist, rdist);
		if(ldist<=rdist) {
			while(q.front()!=a) {
				q.push_back(q.front());
				q.pop_front();
			}
			q.pop_front();
		} else {
			while(q.back()!=a) {
				q.push_front(q.back());
				q.pop_back();
			}
			q.pop_back();
		}
	}
	print(ans);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
