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
const int mxN=2501;
int N, M, dis[mxN], scc[mxN], d, sc, C, ans;
vi adj[mxN];
vii sadj[mxN];
vvi sccs;
stack<int> stk;
unordered_map<string, int> mp;
string s, t;

int dfs(int u) {
	int ret=dis[u]=d++;
	stk.push(u);
	for(int v : adj[u])
		if(dis[v]==-1)
			ret=min(ret, dfs(v));
		else if(scc[v]==-1)
			ret=min(ret, dis[v]);
	if(ret==dis[u]) {
		vi tmp;
		while(1) {
			int t=stk.top();
			stk.pop();
			scc[t]=sc;
			tmp.push_back(t);
			if(t==u)
				break;
		}
		sccs.push_back(tmp);
		++sc;
	}
	return ret;
}

void solve() {
	memset(dis, -1, sizeof(dis));
	memset(scc, -1, sizeof(scc));
	cin >> N;
	for(int i=0; i<N; ++i) {
		cin >> s;
		if(mp.find(s)==mp.end())
			mp[s]=C++;
		int v=mp[s];
		cin >> M;
		while(M--) {
			cin >> t;
			if(mp.find(t)==mp.end())
				mp[t]=C++;
			int u=mp[t];
			adj[u].push_back(v);
		}
	}
	for(int u=0; u<C; ++u)
		if(dis[u]==-1)
			dfs(u);
	cin >> s;
	int idx=mp[s];
	for(int u=0; u<C; ++u)
		for(int v : adj[u])
			if(scc[u]!=scc[v]) 
				sadj[scc[u]].push_back({u, v});
	vl dp(mxN, 1);
	for(int i=sc-1; i; --i)
		for(auto [u, v] : sadj[i])
			dp[v]+=dp[u];
	print(dp[idx]);
}

/*
	3
	A 3 B C D
	B 2 C D
	C 1 D
	A

	A
	A<-B
	A<-C
	A<-D
	A<-B<-C
	A<-B<-D
	A<-C<-D
	A<-B<-C<-D
*/

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
