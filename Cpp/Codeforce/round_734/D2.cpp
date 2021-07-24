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
	int R, C, K;
	cin >> R >> C >> K;
	int cnt=R*C/2;
	int NEW_K=K;
	if(R&1) {
		NEW_K-=C/2;
		cnt-=C/2;
	} else if(C&1) {
		cnt-=R/2;
	}
	if(NEW_K<0||(NEW_K&1)||NEW_K>cnt) {
		print("NO");
		return;
	}
	print("YES");
	vector<vector<char>> ans(R, vector<char>(C, 'a'));
	int NEW_R=R, NEW_C=C;
	if(C&1) {
		for(int i=0; i<R; i+=2) {
			ans[i][C-1]+=(24+((i/2)&1));
			ans[i+1][C-1]+=(24+((i/2)&1));
		}
		--NEW_C;
	} else if(R&1) {
		for(int i=0; i<C; i+=2) {
			ans[R-1][i]+=(24+((i/2)&1));
			ans[R-1][i+1]+=(24+((i/2)&1));
			--K;
		}
		--NEW_R; 
	}
	int r=0, c=0;
	//horizontal
	while(K>0) {
		int t=(r+(c/2))&1;
		ans[r][c]+=t+1;
		ans[r][c+1]+=t+1;
		--K;
		++r;
		if(r>=NEW_R) {
			r=0;
			c+=2;
		}
	}
	for(int r=0; r<NEW_R; r+=2) {
		for(int c=0; c<NEW_C; ++c) {
			if(ans[r][c]!='a'||ans[r+1][c]!='a')
				continue;
			int t=((((r/2)+c))&1)+4;
			ans[r][c]+=t;
			ans[r+1][c]+=t;
		}
	}
	for(int i=0; i<R; ++i) {
		for(int j=0; j<C; ++j)
			cout << ans[i][j];
		cout <<'\n';
	}
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
