#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(int i = 0; i < int(n); ++i)
#define RFOR(n) for(int i = n; ~i; --i)

int calc(vector<int>& box, vector<int>& pos) {
    int n = box.size();
    int m = pos.size();
    vector<int> special(n + 1, 0);
    FOR(n) {
        int p = lower_bound(pos.begin(), pos.end(), box[i]) - pos.begin();
        if(p < m && pos[p] == box[i])
            special[i] = 1;
    }
    RFOR(n - 1) 
        special[i] += special[i + 1];
    FOR(n)
        box[i] -= i;
    int ans = special[0];
    FOR(m) {
        int boxCountLeftOfCurrentSpecialPos = upper_bound(box.begin(), box.end(), pos[i]) - box.begin();
        if(boxCountLeftOfCurrentSpecialPos <= 0)
            continue;
        ans = max(ans, (int)(lower_bound(pos.begin(), pos.end(), pos[i] + boxCountLeftOfCurrentSpecialPos) - pos.begin()) - i + special[boxCountLeftOfCurrentSpecialPos]);
    }

    return ans;
}

void solve() {
    int n, m, v;
    cin >> n >> m;
    vector<int> pos, negPos, box, negBox;
    FOR(n) {
        cin >> v;
        if(v > 0) box.push_back(v);
        else negBox.push_back(-v);
    }
    FOR(m) {
        cin >> v;
        if(v > 0) pos.push_back(v);
        else negPos.push_back(-v);
    }
    sort(negPos.begin(), negPos.end());
    sort(negBox.begin(), negBox.end());
    cout << calc(box, pos) + calc(negBox, negPos) << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCase = 1;
    cin >> testCase;
    for(int t = 0; t < testCase; ++t) 
       solve();

    return 0;
}