#include <bits/stdc++.h>

using namespace std;

unordered_map<char, vector<char>> tree;

void preorder(char u) {
    if(u == '.') {
        return;
    }
    cout << u;
    preorder(tree[u][0]);
    preorder(tree[u][1]);
}

void inorder(char u) {
    if(u == '.') {
        return;
    }
    inorder(tree[u][0]);
    cout << u;
    inorder(tree[u][1]);
}

void postorder(char u) {
    if(u == '.') {
        return;
    }
    postorder(tree[u][0]);
    postorder(tree[u][1]);
    cout << u;
}

void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        char u, l, r;
        cin >> u >> l >> r;
        tree[u].push_back(l);
        tree[u].push_back(r);
    }
    preorder('A');
    cout << endl;
    inorder('A');
    cout << endl;
    postorder('A');
    cout << endl;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}