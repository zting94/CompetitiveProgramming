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
const int mxN=5e3+1;
int N, M, scc[mxN], dis[mxN], s, d, cnt[mxN];
vi adj[mxN];
stack<int> stk;
vvi ans;

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
			tmp.push_back(t);
			scc[t]=s;
			if(t==u)
				break;
		}
		sort(all(tmp));
		ans.push_back(tmp);
		s++;
	}
	return ret;
}

void solve() {
	memset(scc, -1, sizeof(scc));
	memset(dis, -1, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
	for(int i=0; i<N; ++i)
		adj[i].clear();
	stk=stack<int>();
	ans=vvi();
	s=d=0;
	while(M--) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
	}
	for(int i=0; i<N; ++i)
		if(dis[i]==-1)
			dfs(i);
	for(int u=0; u<N; ++u) {
		for(int v : adj[u])
			if(scc[u]!=scc[v])
				cnt[scc[u]]++;
	}
	vi S;
	for(int i=0; i<s; ++i) {
		if(!cnt[i])
			S.insert(S.end(), all(ans[i]));
	}
	sort(all(S));
	for(int i : S)
		cout << i+1 << " ";
	cout << nl;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	while(1) {
		cin >> N;
		if(!N)
			break;
		cin >> M;
		solve();
	}

    return 0;
}
