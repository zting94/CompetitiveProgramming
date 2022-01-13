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
const int mxN=2e4+1;
int N, M, scc[mxN*2], dis[mxN*2], cnt[mxN*2], cnt2[mxN*2], s, d;
vi adj[mxN*2];
stack<int> stk;

int dfs(int u) {
	int ret=dis[u]=d++;
	stk.push(u);
	for(int v : adj[u]) {
		if(dis[v]==-1)
			ret=min(ret, dfs(v));
		else if(scc[v]==-1)
			ret=min(ret, dis[v]);
	}
	if(ret==dis[u]) {
		while(1) {
			int t=stk.top();
			stk.pop();
			scc[t]=s;
			if(t==u)
				break;
		}
		++s;
	}
	return ret;
}

void solve() {
	memset(dis, -1, sizeof(dis));
	memset(scc, -1, sizeof(scc));
	memset(cnt, 0, sizeof(cnt));
	memset(cnt2, 0, sizeof(cnt2));
	s=d=0;
	stk=stack<int>();
	cin >> N >> M;
	for(int i=0; i<N; ++i)
		adj[i].clear();
	for(int i=0; i<M; ++i) {
		int a, b;
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
	}
	for(int i=0; i<N; ++i)
		if(dis[i]==-1)
			dfs(i);
	if(s==1) {
		print(0);
		return;
	}
	for(int u=0; u<N; ++u) {
		for(int v : adj[u]) {
			if(scc[u]==scc[v])
				continue;
			cnt2[scc[u]]++;
			cnt[scc[v]]++;
		}
	}
	int ans1=0, ans2=0;
	for(int i=0; i<s; ++i) {
		ans1+=cnt[i]==0;
		ans2+=cnt2[i]==0;
	}
	print(max(ans1, ans2));
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int tt;
	cin >> tt;
	while(tt--)
		solve();

    return 0;
}
