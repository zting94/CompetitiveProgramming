#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int N;
    cin >> N;
    vector<int> arr(2 * N);
    for (auto& i : arr) {
        cin >> i;
    }
    sort(arr.begin(), arr.end());
    int l = 0, r = arr.size() - 1;
    while(l < r) {
        cout << arr[l++] << " " << arr[r--] << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCase = 1;
    cin >> testCase;
    for (int t = 0; t < testCase; ++t) {
        solve();
    }

    return 0;
}
