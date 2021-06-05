#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

vector<int> tree;
string s;
int K;

void update(int i) {
    if (i >= (1 << (K - 1))) {
        tree[i] = 1 + (s[i] == '?' ? 1 : 0);
        return;
    }
    if (s[i] == '1') {
        tree[i] = tree[i * 2];
    } else if (s[i] == '0') {
        tree[i] = tree[i * 2 + 1];
    } else {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
}

void prop(int i) {
    while (i > 0) {
        update(i);
        i /= 2;
    }
}

void solve() {
    int Q;
    cin >> K >> s >> Q;
    s += '!';
    reverse(s.begin(), s.end());
    tree = vector<int>(1 << K, 1);
    for (int i = (1 << K) - 1; i > 0; --i) {
        update(i);
    }
    for (int i = 0; i < Q; ++i) {
        int idx;
        char ch;
        cin >> idx >> ch;
        idx = (1 << K) - idx;  // reversed
        s[idx] = ch;
        prop(idx);
        cout << tree[1] << '\n';
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
