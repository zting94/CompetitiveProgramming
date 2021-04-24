#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(int i = 0; i < int(n); ++i)
#define RFOR(n) for(int i = int(n); ~i; --i)
#define FORI(i, n) for(int i = 0; i < int(n); ++i)
#define NL '\n'

vector<int> answer;
int inputCount;
bool answerFound;
int n;


void check(vector<int> arr) {
	vector<int> original = arr;
	int cnt = 0;
	FOR(arr.size() - 1) {
		int minIdx = i;
		for(int j = i + 1; j < arr.size(); ++j) {
			if(arr[j] < arr[minIdx]) {
				minIdx = j;
			}
		}
		cnt += (minIdx - i + 1);
		reverse(arr.begin() + i, arr.begin() + minIdx + 1);
	}
	if(cnt == inputCount) {
		answer = original;
		answerFound = true;
	}
}


void backtrack(vector<int>& arr, vector<bool>& used) {
	if(answerFound) {
		return;
	}
	if(arr.size() == n) {
		check(arr);
		return;
	}
	for(int i = 1; i <= n; ++i) {
		if(used[i]) {
			continue;
		}
		used[i] = true;
		arr.push_back(i);
		backtrack(arr, used);
		arr.pop_back();
		used[i] = false;
	}
}

void solve() {
	cin >> n >> inputCount;
	answerFound = false;
	vector<int> arr;
	vector<bool> used(n + 1, false);
	backtrack(arr, used);
	if(answerFound) {
		for(int i : answer) {
			cout << i << " ";
		}
		cout << NL;
	} else {
		cout << "IMPOSSIBLE\n";
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCase = 1;
    cin >> testCase;
    for(int t = 1; t <= testCase; ++t) {
    	cout << "Case #" << t << ": ";
    	solve();
    }

    return 0;
}