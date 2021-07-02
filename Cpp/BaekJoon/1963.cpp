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
void read(vector<T>& v) {
	for(auto& x : v)
		cin >> x;
}

template<typename T>
void read(vector<vector<T>>& v) {
	for(auto& a : v)
		read(a);
}

const int mxN=1e4;
bool p[mxN];

void pre() {
	for(int i=2; i<mxN; ++i)
		p[i]=(i&1)?true:false;
	for(int i=3; i<mxN; i+=2) 
		if(p[i]) 
			for(int j=i*2; j<mxN; j+=i) 
				p[j]=false;
}

void solve() {
	string a, n;
	cin >> a >> n;
	priority_queue<pair<int, string>> pq;
	pq.push({0, a});
	vector<bool> v(mxN, false);
	while(!pq.empty()) {
		auto [d, u]=pq.top();
		pq.pop();
		int num=stoi(u);
		if(u==n) {
			print(-d);
			return;
		}
		if(num<1000||v[num]||!p[num]) 
			continue;
		v[num]=true;
		for(int j=0; j<u.size(); ++j) {
			char c=u[j];
			for(int k=0; k<10; ++k) {
				u[j]='0'+k;
				int t=stoi(u);
				if(!v[t]&&p[t])
					pq.push({d-1, string(u)});
			}
			u[j]=c;
		}
	}
	print("impossible");
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	pre();

	int tt;
	cin >> tt;
	while(tt--)
    	solve();

    return 0;
}
