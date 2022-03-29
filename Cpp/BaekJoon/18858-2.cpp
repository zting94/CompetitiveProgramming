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
const int mxN=1e3+5, mxK=105, M=998244353;
int N, K;
ll dp[mxN][mxK][2], ans;
//dp[i][K][0] == last two number are NOT strictly decreasing
//dp[i][K][1] == last two number are strictly decreasing
//we can do it in reverse order(?)

void solve() {
    cin >> N >> K;
    for(int i=1; i<=K; ++i)
        dp[1][i][0]=1;
    for(int i=2; i<=N; ++i) {
        for(int j=K; j>=0; --j) {
            dp[i-1][j][0]+=dp[i-1][j+1][0];
            dp[i-1][j][0]%=M;
            dp[i-1][j][1]+=dp[i-1][j+1][1];
            dp[i-1][j][1]%=M;
        }
        for(int j=1; j<=K; ++j) {
            dp[i][j][0]=(dp[i-1][0][0]-dp[i-1][j+1][0]+M+dp[i-1][j][1]-dp[i-1][j+1][1]+M)%M;
            dp[i][j][1]=(dp[i-1][j+1][0]+dp[i-1][j+1][1])%M;
        }
    }
    for(int i=1; i<=K; ++i)
        ans=(ans+dp[N][i][0]+dp[N][i][1])%M;
    print(ans);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
 
