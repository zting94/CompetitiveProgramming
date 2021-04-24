#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    stack<int> stk;
    int ans = 0;
    for(int i = 0; i < n + 1; ++i) {
        while(!stk.empty() && arr[i] <= arr[stk.top()]) {
            int h = arr[stk.top()];
            stk.pop();
            int w = i;
            if(!stk.empty())
                w = i - stk.top() - 1;
            ans = max(ans, w * h);
        }
        stk.push(i);
    }
    cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}