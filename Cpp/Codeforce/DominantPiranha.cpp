#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int maxVal = 0;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        maxVal = max(maxVal, arr[i]);
    }
    int idx = -1;
    for(int i = 0; i < n; ++i) {
        if(arr[i] != maxVal) {
            continue;
        }
        if(i > 0 && arr[i - 1] < arr[i]) {
            idx = i + 1;
        }
        if(i < n - 1 && arr[i + 1] < arr[i]) {
            idx = i + 1;
        }
    }
    cout << idx << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCase = 1;
    cin >> testCase;
    for(int t = 0; t < testCase; ++t)  {
       solve();
    }

    return 0;
}