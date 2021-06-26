
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

void solve() {
	int n;
	cin >> n;
	vector<bool> vis(n+1, false);
	vector<int> ans;
	vector<int> tmp{n};
	queue<pair<int, vector<int>>> q;
	q.push({n, tmp});
	while(!q.empty()) {
		auto [d, path]=q.front();
		q.pop();
		if(vis[d])
			continue;
		vis[d]=true;
		if(d==1) {
			ans=path;
			break;
		}
		if(d%3==0) {
			path.push_back(d/3);
			q.push({d/3, path});
			path.pop_back();
		}
		if(d%2==0) {
			path.push_back(d/2);
			q.push({d/2, path});
			path.pop_back();
		}
		path.push_back(d-1);
		q.push({d-1, path});
	}
	print(ans.size()-1);
	print(ans);
}


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
