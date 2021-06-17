#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int M=1e4;

void solve() {
	int a, b;
	cin >> a >> b;
	queue<int> q;
	q.push(a);
	vector<bool> vis(M+1, false);
	vis[a]=true;
	vector<int> from(M+1, -1);
	vector<char> com(M+1, ' ');
	while(!q.empty()) {
		int v=q.front();
		q.pop();
		int t=(2*v)%M;
		if(!vis[t]) {
			q.push(t);
			from[t]=v;
			com[t]='D';
			vis[t]=true;
		}
		t=(v-1+M)%M;
		if(!vis[t]) {
			q.push(t);
			from[t]=v;
			com[t]='S';
			vis[t]=true;
		}
		t=((v%1000)*10)+v/1000;
		if(!vis[t]) {
			q.push(t);
			from[t]=v;
			com[t]='L';
			vis[t]=true;
		}
		t=((v%10)*1000)+v/10;
		if(!vis[t]) {
			q.push(t);
			from[t]=v;
			com[t]='R';
			vis[t]=true;
		}
	}
	vector<char> ans;
	while(b!=a) {
		assert(com[b]!=' ');
		ans.push_back(com[b]);
		b=from[b];
	}
	for(int i=ans.size()-1; i>=0; --i) {
		cout << ans[i];
	}
	cout << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int tt;
	cin >> tt;
	while(tt--) {
    	solve();
	}

    return 0;
}
