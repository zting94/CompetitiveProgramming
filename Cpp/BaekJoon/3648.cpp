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
const int mxN=1e3+1;
int N, M, dis[mxN*2], scc[mxN*2], d, s;
vi adj[mxN*2];
stack<int> stk;

int op(int i) {
	return i>=N?i-N:i+N;
}

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
	d=s=0;
	for(int i=0; i<=2*N; ++i)
		adj[i].clear();
	stk=stack<int>();
	adj[op(0)].push_back(0); // key point
	for(int i=0; i<M; ++i) {
		int u, v;
		cin >> u >> v;
		u=u<0?op(abs(u+1)):u-1;
		v=v<0?op(abs(v+1)):v-1;
		adj[op(u)].push_back(v);
		adj[op(v)].push_back(u);
	}
	for(int i=0; i<N; ++i) {
		if(dis[i]==-1)
			dfs(i);
		if(dis[op(i)]==-1)
			dfs(op(i));
	}
	for(int i=0; i<N; ++i) {
		if(scc[i]==scc[op(i)]) {
			print("no");
			return;
		}
	}
	print("yes");
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	while(cin >> N >> M) 
		solve();

    return 0;
}
