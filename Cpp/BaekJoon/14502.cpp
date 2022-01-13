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

void __zbg(int v) { cerr << v; }
void __zbg(long v) { cerr << v; }
void __zbg(ll v) { cerr << v; }
void __zbg(unsigned v) { cerr << v; }
void __zbg(unsigned long v) { cerr << v; }
void __zbg(ull v) { cerr << v; }
void __zbg(float v) { cerr << v; }
void __zbg(double v) { cerr << v; }
void __zbg(long double v) { cerr << v; }
void __zbg(char v) { cerr << '\'' << v << '\''; }
void __zbg(const char* v) { cerr << '\'' << v << '\''; }
void __zbg(const string& v) { cerr << '\'' << v << '\''; }
void __zbg(bool v) { cerr << v?"true":"false"; }

template<typename T, typename V>
void __zbg(const pair<T, V>& v) {
	cerr << '{';
	__zbg(v.first);
	cerr << ", ";
	__zbg(v.second);
	cerr << '}';
}

template<typename T>
void __zbg(const T& x) {
	int f=0;
	cerr << '{';
	for (auto &i : x) {
		cerr << (f++?", ":"");
		__zbg(i);
	}
	cerr << '}';
}

void _zbg() { cerr << "]\n"; }

template<typename T, typename... V>
void _zbg(T t, V... v) {
	__zbg(t);
	if(sizeof...(v))
		cerr << ", ";
	_zbg(v...);
}
//#define dbg(x...) cerr << "\033[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _zbg(x); cerr << "\033[39m" << endl;
#define dbg(x...) cerr << __func__<<":"<<__LINE__<<" [" << #x << "] = ["; _zbg(x); cerr << endl;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).begin(), (x).end()

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

const int mxN=9;
const int dr[4]={-1, 0, 1, 0}, dc[4]={0, -1, 0, 1};
int N, M, A[mxN][mxN], tmp[mxN][mxN], openCnt;
vii virus, opens;

bool can(int i, int j) {
	return i>=0&&j>=0&&N>i&&M>j;
}

int bfs() {
	queue<pii> q;
	int ret=openCnt;
	for(auto [x, y] : virus)  {
		q.push({x, y});
		tmp[x][y]=0;
		++ret;
	}
	while(!q.empty()) {
		auto [x, y]=q.front();
		q.pop();
		if(tmp[x][y]!=0)
			continue;
		tmp[x][y]=2;
		--ret;
		for(int i=0; i<4; ++i) {
			int xx=x+dr[i], yy=y+dc[i];
			if(can(xx, yy)&&tmp[xx][yy]==0)
				q.push({xx, yy});
		}
	}
	return ret;
}

void solve() {
	cin >> N >> M;
	for(int i=0; i<N; ++i) {
		for(int j=0; j<M; ++j) {
			cin >> A[i][j];
			if(A[i][j]==2)
				virus.push_back({i, j});
			if(A[i][j]==0) {
				opens.push_back({i, j});
				openCnt++;
			}
		}
	}
	int ans=0;
	for(int i=0; i<opens.size()-2; ++i) {
		for(int j=i+1; j<opens.size()-1; ++j) {
			for(int k=j+1; k<opens.size(); ++k) {
				memcpy(tmp, A, sizeof(A));
				tmp[opens[i].first][opens[i].second]=tmp[opens[j].first][opens[j].second]=tmp[opens[k].first][opens[k].second]=1;
				ans=max(ans, bfs()-3);
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
