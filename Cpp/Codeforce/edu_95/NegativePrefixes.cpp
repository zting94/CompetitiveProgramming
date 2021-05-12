#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> lock(n);
    vector<int> nums;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> lock[i];
        if(lock[i] == 0) {
            nums.push_back(arr[i]);
        }
    }
    sort(nums.rbegin(), nums.rend());
    int idx = 0;
    for(int i = 0; i < n; ++i) {
        if(lock[i] == 0) {
            arr[i] = nums[idx++];
        }
        cout << arr[i] << ' ';
    }
    cout << '\n';
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