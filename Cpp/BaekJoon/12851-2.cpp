#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

template<typename T>
void print(const vector<vector<T>>& v, char sp=' ') {
	int n=v.size();
	if(n==0)
		return;
	int m=v[0].size();
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			if(j>0)
				cout << sp;
			cout << v[i][j];
		}
		cout << '\n';
	}
}

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
void print(T v) {
	cout << v << '\n';
}

template<typename T>
void read(vector<vector<T>>& v) {
	for(auto& a : v)
		for(auto& i : a)
			cin >> i;
}

template<typename T>
void read(vector<T>& v) {
	for(auto& x : v)
		cin >> x;
}

const int mxK=1e5;
int vis[mxK+1];

void solve() {
	int n, k;
	cin >> n >> k;
	memset(vis, 0, sizeof(vis));
	int ans=0, t=0;
	queue<int> q;
	q.push(n);
	while(!q.empty()) {
		int sz=q.size();
		for(int i=0; i<sz; ++i) {
			int v=q.front();
			q.pop();
			ans+=v==k;
			for(auto next : {v-1, v+1, 2*v}) {
				if(next<0||next>mxK)
					continue;
				//need to count different paths which produce same N
				if(!vis[next]||vis[next]==vis[v]+1) {
					vis[next]=vis[v]+1;
					q.push(next);
				}
			}
		}
		if(ans)
			break;
		++t;
	}
	print(t);
	print(ans);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
