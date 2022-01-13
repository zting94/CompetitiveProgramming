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

class Face {
public:
	Face() {
		c=vvi(3, vi(3));
	}
	void fill(int v) {
		for(auto& i : c)
			for(auto& j : i)
				j=v;
	}
	vvi c;
};

const int dx[4]={-1, 0, 1, 0}, dy[4]={0, -1, 0, 1};
const int TOP=0, RIGHT=1, FRONT=2, LEFT=3, BACK=4, BOTTOM=5;
string color[6]={"w", "b", "r", "g", "o", "y"};
Face face[6];

void init() {
	for(int i=0; i<6; ++i)
		face[i].fill(i);
}

void rotateFaceClock(int idx) {
	vvi& fc=face[idx].c;
	swap(fc[0][0], fc[2][2]);
	swap(fc[0][1], fc[1][2]);
	swap(fc[1][0], fc[2][1]);
	for(int i=0; i<3; ++i)
		swap(fc[0][i], fc[2][i]);
}

void rotateFaceCounterClock(int idx) {
	vvi& fc=face[idx].c;
	swap(fc[0][2], fc[2][0]);
	swap(fc[0][1], fc[1][0]);
	swap(fc[1][2], fc[2][1]);
	for(int i=0; i< 3; ++i)
		swap(fc[0][i], fc[2][i]);
}

/*
			BACK	
	LEFT	TOP 	RIGHT 	BOTTOM
			FRONT

			8 7 6
			5 4 3
			2 1 0

	6 3 0	0 1 2	2 5 8	2 1 0
	7 4 1	3 4 5	1 4 7	5 4 3
	8 5	2	6 7 8	0 3 6	8 7 6

			0 1 2
			3 4 5
			6 7 8
*/

void topClock() {
	rotateFaceClock(TOP);
	auto temp=face[BACK].c[0];
	for(int i=4; i>1; --i)
		face[i].c[0]=face[i-1].c[0];
	face[RIGHT].c[0]=temp;
}

/*
			BACK	
	LEFT	TOP 	RIGHT 	BOTTOM
			FRONT

			8 7 6
			5 4 3
			2 1 0

	6 3 0	0 1 2	2 5 8	2 1 0
	7 4 1	3 4 5	1 4 7	5 4 3
	8 5	2	6 7 8	0 3 6	8 7 6

			0 1 2
			3 4 5
			6 7 8
*/

void topCounterClock() {
	rotateFaceCounterClock(TOP);
	auto temp=face[RIGHT].c[0];
	for(int i=1; i<4; ++i)
		face[i].c[0]=face[i+1].c[0];
	face[BACK].c[0]=temp;
}

/*
			BACK	
	LEFT	TOP 	RIGHT 	BOTTOM
			FRONT

			8 7 6
			5 4 3
			2 1 0

	6 3 0	0 1 2	2 5 8	2 1 0
	7 4 1	3 4 5	1 4 7	5 4 3
	8 5	2	6 7 8	0 3 6	8 7 6

			0 1 2
			3 4 5
			6 7 8
*/

void rightClock() {
	rotateFaceClock(RIGHT);
	auto& top=face[TOP].c, &front=face[FRONT].c, &back=face[BACK].c, &bottom=face[BOTTOM].c;
	int t0=bottom[0][0], t1=bottom[1][0], t2=bottom[2][0];
	bottom[0][0]=back[0][0], bottom[1][0]=back[1][0], bottom[2][0]=back[2][0];
	back[0][0]=top[2][2], back[1][0]=top[1][2], back[2][0]=top[0][2];
	top[0][2]=front[0][2], top[1][2]=front[1][2], top[2][2]=front[2][2];
	front[0][2]=t2, front[1][2]=t1, front[2][2]=t0;
}

/*
			BACK	
	LEFT	TOP 	RIGHT 	BOTTOM
			FRONT

			8 7 6
			5 4 3
			2 1 0

	6 3 0	0 1 2	2 5 8	2 1 0
	7 4 1	3 4 5	1 4 7	5 4 3
	8 5	2	6 7 8	0 3 6	8 7 6

			0 1 2
			3 4 5
			6 7 8
*/

void rightCounterClock() {
	rotateFaceCounterClock(RIGHT);
	auto& top=face[TOP].c, &front=face[FRONT].c, &back=face[BACK].c, &bottom=face[BOTTOM].c;
	int t0=bottom[0][0], t1=bottom[1][0], t2=bottom[2][0];
	bottom[0][0]=front[2][2], bottom[1][0]=front[1][2], bottom[2][0]=front[0][2];
	front[0][2]=top[0][2], front[1][2]=top[1][2], front[2][2]=top[2][2];
	top[0][2]=back[2][0], top[1][2]=back[1][0], top[2][2]=back[0][0];
	back[0][0]=t0, back[1][0]=t1, back[2][0]=t2;
}

/*
			BACK	
	LEFT	TOP 	RIGHT 	BOTTOM
			FRONT

			8 7 6
			5 4 3
			2 1 0

	6 3 0	0 1 2	2 5 8	2 1 0
	7 4 1	3 4 5	1 4 7	5 4 3
	8 5	2	6 7 8	0 3 6	8 7 6

			0 1 2
			3 4 5
			6 7 8
*/

void leftClock() {
	rotateFaceClock(LEFT);
	auto& front=face[FRONT].c, &top=face[TOP].c, &back=face[BACK].c, &bottom=face[BOTTOM].c;
	int t0=front[0][0], t1=front[1][0], t2=front[2][0];
	front[0][0]=top[0][0], front[1][0]=top[1][0], front[2][0]=top[2][0];
	top[0][0]=back[2][2], top[1][0]=back[1][2], top[2][0]=back[0][2];
	back[0][2]=bottom[0][2], back[1][2]=bottom[1][2], back[2][2]=bottom[2][2];
	bottom[0][2]=t2, bottom[1][2]=t1, bottom[2][2]=t0;
}

/*
			BACK	
	LEFT	TOP 	RIGHT 	BOTTOM
			FRONT

			8 7 6
			5 4 3
			2 1 0

	6 3 0	0 1 2	2 5 8	2 1 0
	7 4 1	3 4 5	1 4 7	5 4 3
	8 5	2	6 7 8	0 3 6	8 7 6

			0 1 2
			3 4 5
			6 7 8
*/

void leftCounterClock() {
	rotateFaceCounterClock(LEFT);
	auto& front=face[FRONT].c, &top=face[TOP].c, &back=face[BACK].c, &bottom=face[BOTTOM].c;
	int t0=front[0][0], t1=front[1][0], t2=front[2][0];
	front[0][0]=bottom[2][2], front[1][0]=bottom[1][2], front[2][0]=bottom[0][2];
	bottom[0][2]=back[0][2], bottom[1][2]=back[1][2], bottom[2][2]=back[2][2];
	back[2][2]=top[0][0], back[1][2]=top[1][0], back[0][2]=top[2][0];
	top[0][0]=t0, top[1][0]=t1, top[2][0]=t2;
}

/*
			BACK	
	LEFT	TOP 	RIGHT 	BOTTOM
			FRONT

			8 7 6
			5 4 3
			2 1 0

	6 3 0	0 1 2	2 5 8	2 1 0
	7 4 1	3 4 5	1 4 7	5 4 3
	8 5	2	6 7 8	0 3 6	8 7 6

			0 1 2
			3 4 5
			6 7 8
*/

void bottomClock() {
	rotateFaceClock(BOTTOM);
	auto temp=face[RIGHT].c[2];
	for(int i=1; i<4; ++i)
		face[i].c[2]=face[i+1].c[2];
	face[BACK].c[2]=temp;
}

/*
			BACK	
	LEFT	TOP 	RIGHT 	BOTTOM
			FRONT

			8 7 6
			5 4 3
			2 1 0

	6 3 0	0 1 2	2 5 8	2 1 0
	7 4 1	3 4 5	1 4 7	5 4 3
	8 5	2	6 7 8	0 3 6	8 7 6

			0 1 2
			3 4 5
			6 7 8
*/

void bottomCounterClock() {
	rotateFaceCounterClock(BOTTOM);
	auto temp=face[BACK].c[2];
	for(int i=4; i>1; --i)
		face[i].c[2]=face[i-1].c[2];
	face[RIGHT].c[2]=temp;
}

/*
			BACK	
	LEFT	TOP 	RIGHT 	BOTTOM
			FRONT

			->
			8 7 6
			5 4 3
			2 1 0

	6 3 0	0 1 2	2 5 8	2 1 0
	7 4 1	3 4 5	1 4 7	5 4 3
	8 5	2	6 7 8	0 3 6	8 7 6

			0 1 2
			3 4 5
			6 7 8
*/

void backClock() {
	rotateFaceClock(BACK);
	auto& top=face[TOP].c, &left=face[LEFT].c, &right=face[RIGHT].c, &bottom=face[BOTTOM].c;
	int t0=top[0][0], t1=top[0][1], t2=top[0][2];
	top[0][0]=right[0][2], top[0][1]=right[1][2], top[0][2]=right[2][2];
	right[0][2]=bottom[0][0], right[1][2]=bottom[0][1], right[2][2]=bottom[0][2];
	bottom[0][0]=left[2][0], bottom[0][1]=left[1][0], bottom[0][2]=left[0][0];
	left[0][0]=t2, left[1][0]=t1, left[2][0]=t0;
}

/*
			BACK	
	LEFT	TOP 	RIGHT 	BOTTOM
			FRONT

			8 7 6
			5 4 3
			2 1 0

	6 3 0	0 1 2	2 5 8	2 1 0
	7 4 1	3 4 5	1 4 7	5 4 3
	8 5	2	6 7 8	0 3 6	8 7 6

			0 1 2
			3 4 5
			6 7 8
*/

void backCounterClock() {
	rotateFaceCounterClock(BACK);
	auto& top=face[TOP].c, &left=face[LEFT].c, &right=face[RIGHT].c, &bottom=face[BOTTOM].c;
	int t0=top[0][0], t1=top[0][1], t2=top[0][2];
	top[0][0]=left[2][0], top[0][1]=left[1][0], top[0][2]=left[0][0];
	left[2][0]=bottom[0][0], left[1][0]=bottom[0][1], left[0][0]=bottom[0][2];
	bottom[0][0]=right[0][2], bottom[0][1]=right[1][2], bottom[0][2]=right[2][2];
	right[0][2]=t0, right[1][2]=t1, right[2][2]=t2;
}

/*
			BACK	
	LEFT	TOP 	RIGHT 	BOTTOM
			FRONT

			8 7 6
			5 4 3
			2 1 0

	6 3 0	0 1 2	2 5 8	2 1 0
	7 4 1	3 4 5	1 4 7	5 4 3
	8 5	2	6 7 8	0 3 6	8 7 6

			0 1 2
			3 4 5
			6 7 8
*/

void frontClock() {
	rotateFaceClock(FRONT);
	auto& top=face[TOP].c, &right=face[RIGHT].c, &left=face[LEFT].c, &bottom=face[BOTTOM].c;
	int t0=top[2][0], t1=top[2][1], t2=top[2][2];
	top[2][0]=left[2][2], top[2][1]=left[1][2], top[2][2]=left[0][2];
	left[2][2]=bottom[2][0], left[1][2]=bottom[2][1], left[0][2]=bottom[2][2];
	bottom[2][0]=right[0][0], bottom[2][1]=right[1][0], bottom[2][2]=right[2][0];
	right[0][0]=t0, right[1][0]=t1, right[2][0]=t2;
}

/*
			BACK	
	LEFT	TOP 	RIGHT 	BOTTOM
			FRONT

			8 7 6
			5 4 3
			2 1 0

	6 3 0	0 1 2	2 5 8	2 1 0
	7 4 1	3 4 5	1 4 7	5 4 3
	8 5	2	6 7 8	0 3 6	8 7 6

			0 1 2
			3 4 5
			6 7 8
*/

void frontCounterClock() {
	rotateFaceCounterClock(FRONT);
	auto& top=face[TOP].c, &right=face[RIGHT].c, &left=face[LEFT].c, &bottom=face[BOTTOM].c;
	int t0=top[2][0], t1=top[2][1], t2=top[2][2];
	top[2][0]=right[0][0], top[2][1]=right[1][0], top[2][2]=right[2][0];
	right[0][0]=bottom[2][0], right[1][0]=bottom[2][1], right[2][0]=bottom[2][2];
	bottom[2][0]=left[2][2], bottom[2][1]=left[1][2], bottom[2][2]=left[0][2];
	left[2][2]=t0, left[1][2]=t1, left[0][2]=t2;
}

void solve() {
	init();
	string s;
	int N;
	cin >> N;
	for(int i=0; i<N; ++i) {
		cin >> s;
		if(s[0]=='U') {
			if(s[1]=='+') topClock();
			else topCounterClock();
		} else if(s[0]=='D') {
			if(s[1]=='+') bottomClock();
			else bottomCounterClock();
		} else if(s[0]=='L') {
			if(s[1]=='+') leftClock();
			else leftCounterClock();
		} else if(s[0]=='R') {
			if(s[1]=='+') rightClock();
			else rightCounterClock();
		} else if(s[0]=='B') {
			if(s[1]=='+') backClock();
			else backCounterClock();
		} else if(s[0]=='F') {
			if(s[1]=='+') frontClock();
			else frontCounterClock();
		} else
			assert(false);
	}
	for(int i=0; i<3; ++i) {
		for(int j=0; j<3; ++j) {
			cout << color[face[TOP].c[i][j]];
		}
		cout << nl;
	}
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
