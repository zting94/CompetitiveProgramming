#include <bits/stdc++.h>

using namespace std;

class Trie {
public :
    bool isEnd;
    Trie* next[10];
    Trie() : isEnd(false) {
        memset(next, 0, sizeof(next));
    }
    ~Trie() {
        for(int i = 0; i < 10; ++i) {
            if(next[i]) {
                delete next[i];
            }
        }
    }
    bool hasChild() const {
        for(int i = 0; i < 10; ++i) {
            if(next[i]) {
                return true;
            }
        }
        return false;
    }
};

Trie* root;

bool solve() {
    root = new Trie();
    int n;
    string s;
    cin >> n;
    vector<Trie*> leaves(n);
    for(int i = 0; i < n; ++i) {
        cin >> s;
        Trie* cur = root;
        for(char c : s) {
            int idx = c - '0';
            if(cur->next[idx] == nullptr) {
                cur->next[idx] = new Trie();
            }
            cur = cur->next[idx];
        }
        cur->isEnd = true;
        leaves[i] = cur;
    }

    bool result = true;
    for(Trie* leaf : leaves) {
        if(leaf->hasChild()) {
            result = false;
            break;
        }
    }

    delete root;

    return result;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCase = 1;
    cin >> testCase;
    for(int t = 0; t < testCase; ++t)  {
        if(solve()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}