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
#define nl '\n'

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

const int dx[4]={-1, 0, 1, 0}, dy[4]={0, -1, 0, 1};

void solve() {
	int N, M;
	cin >> N;
	vii A(N), B(N);
	for(int i=0; i<N; ++i) {
		cin >> A[i].first;
		A[i].second=i;
		B[i].first=A[i].first;
		B[i].second=i;
	}
	sort(all(A));
	reverse(all(B));
	cin >> M;
	string ans;
	if(A[0].second==0) {
		if(N==1||A[1].first>M) {
			print(0);
			return;
		}
	}
	if(A[0].second==0) {
		ans+='0'+A[1].second;
		M-=A[1].first;
	} else {
		ans+='0'+A[0].second;
		M-=A[0].first;
	}
	while(M>=A[0].first) {
		ans+='0'+A[0].second;
		M-=A[0].first;
	}
	for(int i=0; i<ans.size(); ++i) {
		for(int j=0; j<N; ++j) {
			int c=ans[i]-'0';
			if(B[j].second<=c)
				continue;
			int diff=B[j].first-B[N-c-1].first;
			if(M>=diff) {
				M-=diff;
				ans[i]='0'+B[j].second;
				break;
			}
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
