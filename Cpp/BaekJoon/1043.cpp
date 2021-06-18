#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

class Party {
public :
	Party(int sz) {
		parent=vector<int>(sz+1, 0);
		truth=vector<bool>(sz+1, false);
		for(int i=1; i<=sz; ++i)
			parent[i]=i;
	}
	int find(int a) {
		if(parent[a]==a) {
			return a;
		}
		int pa=find(parent[a]);
		truth[pa]=truth[a]|truth[pa];
		return parent[a]=pa;
	}
	void merge(int a, int b) {
		int pa=find(a);
		int pb=find(b);
		if(pa<pb) {
			truth[pa]=truth[pa]|truth[pb];
			truth[pb]=truth[pb]|truth[pa];
			parent[pb]=pa;
		} else {
			truth[pa]=truth[pa]|truth[pb];
			truth[pb]=truth[pb]|truth[pa];
			parent[pa]=pb;
		}
	}
	void setTruth(int i) {
		truth[i]=true;
	}
	bool knowTruth(int i) {
		return truth[i];
	}
	int liePartyCount() {
		int ans=0;
		for(int i=1; i<truth.size(); ++i) {
			ans+=!truth[find(i)];
		}
		return ans;
	}
	vector<int> parent;
	vector<bool> truth;
};

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	Party u(m);
	vector<vector<int>> person(n+1);
	unordered_set<int> s;
	for(int i=0; i<k; ++i) {
		int t;
		cin >> t;
		s.insert(t);
	}
	for(int i=1; i<=m; ++i) {
		int sz;
		cin >> sz;
		for(int j=0; j<sz; ++j) {
			int p;
			cin >> p;
			person[p].push_back(i);
			if(s.find(p)!=s.end())
				u.setTruth(i);
		}
	}
	for(int i=1; i<=n; ++i) {
		int prev=-1;
		for(int j=0; j<person[i].size(); ++j) {
			if(prev!=-1)
				u.merge(prev, person[i][j]);
			prev=person[i][j];
		}
	}
	cout << u.liePartyCount() << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
