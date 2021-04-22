#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int left = 0;
    for(int i = 0; i < n; ++i) {
        if(arr[i] == 1) {
            left = i;
            break;
        }
    }
    int right = n - 1;
    for(int i = n - 1; i >= 0; --i) {
        if(arr[i] == 1) {
            right = i;
            break;
        }
    }
    cout << count(arr.begin() + left, arr.begin() + right, 0) << '\n';
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