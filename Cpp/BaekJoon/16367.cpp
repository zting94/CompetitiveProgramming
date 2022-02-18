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
const int mxN=1e4+1;
int N, K, scc[mxN*2], dis[mxN*2], s, d, ans[mxN*2];
vi adj[mxN*2];
stack<int> stk;
vvi sccs;

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
		vi tmp;
		while(1) {
			int t=stk.top();
			stk.pop();
			scc[t]=s;
			tmp.push_back(t);
			if(t==u)
				break;
		}
		sort(all(tmp));
		sccs.push_back(tmp);
		++s;
	}
	return ret;
}

// red = true

void solve() {
	memset(scc, -1, sizeof(scc));
	memset(dis, -1, sizeof(dis));
	cin >> N >> K;
	while(K--) {
		int a, b, c;
		char ca, cb, cc;
		cin >> a >> ca >> b >> cb >> c >> cc, --a, --b, --c;
		a=ca=='B'?op(a):a;
		b=cb=='B'?op(b):b;
		c=cc=='B'?op(c):c;
		adj[op(a)].push_back(b);
		adj[op(b)].push_back(a);
		adj[op(b)].push_back(c);
		adj[op(c)].push_back(b);
		adj[op(c)].push_back(a);
		adj[op(a)].push_back(c);
	}
	for(int i=0; i<N; ++i) {
		if(dis[i]==-1)
			dfs(i);
		if(dis[op(i)]==-1)
			dfs(op(i));
	}
	for(int i=0; i<N; ++i) {
		if(scc[i]==scc[op(i)]) {
			print(-1);
			return;
		}
	}
	for(auto ss : sccs) {
		for(int s : ss) {
			if(ans[s]) 
				continue;
			ans[s]='R';
			ans[op(s)]='B';
		}
	}
	for(int i=0; i<N; ++i)
		cout << (char)ans[i];
	cout << nl;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
